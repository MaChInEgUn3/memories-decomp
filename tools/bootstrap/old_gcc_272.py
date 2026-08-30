#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import os
import shutil
import sys
import tarfile
from pathlib import Path
from typing import Any

PROJECT_TOOLS = Path(__file__).resolve().parents[1] / "project"
sys.path.insert(0, str(PROJECT_TOOLS))

from old_gcc import (  # noqa: E402
    CompilerError,
    check_compiler,
    clone_repository,
    compiler_paths,
    download_source,
    run,
    sha256_file,
    validate_tar_members,
    verify_hash,
)
from workspace import (  # noqa: E402
    WorkspaceError,
    require_workspace_root,
    resolve_within,
)


def load_lock(root: Path) -> dict[str, Any]:
    path = resolve_within(
        root, "tools/bootstrap/old_gcc_272.json", must_exist=True
    )
    with path.open("r", encoding="utf-8") as handle:
        lock = json.load(handle)
    if lock.get("schema") != 1:
        raise CompilerError(f"{path}: unsupported lock schema")
    return lock


def source_marker(source: Path) -> Path:
    return source / ".project-source.json"


def expected_source_marker(lock: dict[str, Any]) -> dict[str, Any]:
    return {
        "source_sha256": lock["source"]["sha256"],
        "archive_root": "gcc-2.7.2",
    }


def check_source(root: Path, lock: dict[str, Any]) -> Path:
    source = resolve_within(
        root, str(lock["source"]["destination"]), must_exist=True
    )
    marker = source_marker(source)
    if not marker.is_file() or not (source / "configure").is_file():
        raise CompilerError(f"incomplete GCC 2.7.2 source tree: {source}")
    with marker.open("r", encoding="utf-8") as handle:
        actual = json.load(handle)
    if actual != expected_source_marker(lock):
        raise CompilerError(f"{source}: source marker does not match the lock")
    return source


def extract_source(root: Path, lock: dict[str, Any], archive_path: Path) -> Path:
    destination = resolve_within(root, str(lock["source"]["destination"]))
    if destination.exists():
        return check_source(root, lock)

    staging_root = resolve_within(root, "tmp/bootstrap/gcc-2.7.2-source")
    if staging_root.exists():
        raise CompilerError(f"stale source staging path exists: {staging_root}")
    staging_root.mkdir(parents=True)

    with tarfile.open(archive_path, "r:gz") as archive:
        validate_tar_members(archive)
        archive.extractall(staging_root)

    extracted = staging_root / "gcc-2.7.2"
    if not extracted.is_dir():
        raise CompilerError(f"{archive_path}: missing gcc-2.7.2 source directory")
    source_marker(extracted).write_text(
        json.dumps(
            expected_source_marker(lock),
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )
    destination.parent.mkdir(parents=True, exist_ok=True)
    extracted.replace(destination)
    staging_root.rmdir()
    return check_source(root, lock)


def make_writable(source: Path) -> None:
    for path in source.rglob("*"):
        if path.is_file():
            path.chmod(path.stat().st_mode | 0o200)


def apply_build_patches(
    root: Path,
    lock: dict[str, Any],
    repository: Path,
    build: Path,
) -> None:
    make_writable(build)
    for source_file in build.glob("*.c"):
        text = source_file.read_text(encoding="latin-1")
        updated = text.replace("include <varargs.h>", "include <stdarg.h>")
        if updated != text:
            source_file.write_text(updated, encoding="latin-1")

    for patch in lock["patches"]:
        patch_path = repository / str(patch["path"])
        verify_hash(patch_path, str(patch["sha256"]))
        run(
            root,
            [
                "patch",
                *[str(argument) for argument in patch["arguments"]],
                "-i",
                str(patch_path),
            ],
            cwd=build,
        )

    host_patch = resolve_within(
        root, str(lock["host_patch"]["path"]), must_exist=True
    )
    verify_hash(host_patch, str(lock["host_patch"]["sha256"]))
    run(
        root,
        [
            "patch",
            *[str(argument) for argument in lock["host_patch"]["arguments"]],
            "-i",
            str(host_patch),
        ],
        cwd=build,
    )


def build_compiler(
    root: Path,
    lock: dict[str, Any],
    repository: Path,
    source: Path,
) -> None:
    paths = compiler_paths(root, lock)
    prefix = resolve_within(root, str(lock["prefix"]))
    if prefix.exists():
        raise CompilerError(
            f"incomplete GCC 2.7.2 prefix exists; remove it before retrying: {prefix}"
        )
    build = resolve_within(root, str(lock["build"]))
    if build.exists():
        raise CompilerError(
            f"stale GCC 2.7.2 build exists; remove it before retrying: {build}"
        )
    shutil.copytree(source, build)

    run(
        root,
        [
            "./configure",
            f"--target={lock['target']}",
            f"--prefix={prefix}",
            "--with-endian-little",
            "--with-gnu-as",
            "--disable-gprof",
            "--disable-gdb",
            "--disable-werror",
            "--host=i386-pc-linux",
            "--build=i386-pc-linux",
        ],
        cwd=build,
    )
    apply_build_patches(root, lock, repository, build)

    jobs = max(1, min(os.cpu_count() or 1, 4))
    run(
        root,
        [
            "make",
            f"-j{jobs}",
            "cpp",
            "cc1",
            "xgcc",
            f"CFLAGS={lock['host_cflags']}",
        ],
        cwd=build,
    )

    library = paths["cc1"].parent
    paths["gcc"].parent.mkdir(parents=True, exist_ok=True)
    library.mkdir(parents=True, exist_ok=True)
    shutil.copy2(build / "xgcc", paths["gcc"])
    shutil.copy2(build / "cc1", paths["cc1"])
    shutil.copy2(build / "cpp", paths["cpp"])
    for path in (paths["gcc"], paths["cc1"], paths["cpp"]):
        path.chmod(0o755)

    license_directory = prefix / "share/licenses/gcc-2.7.2"
    license_directory.mkdir(parents=True, exist_ok=True)
    shutil.copy2(build / "COPYING", license_directory / "COPYING")

    manifest = {
        "repository_commit": lock["repository"]["commit"],
        "repository_tree": lock["repository"]["tree"],
        "source_sha256": lock["source"]["sha256"],
        "target": lock["target"],
        "version": lock["version"],
        "host_cflags": lock["host_cflags"],
        "probe_flags": lock["probe_flags"],
        "host_patch_sha256": lock["host_patch"]["sha256"],
        "sha256": {
            "gcc": sha256_file(paths["gcc"]),
            "cc1": sha256_file(paths["cc1"]),
            "cpp": sha256_file(paths["cpp"]),
        },
    }
    paths["manifest"].write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n",
        encoding="utf-8",
    )
    check_compiler(root, lock)


def install(root: Path, lock: dict[str, Any]) -> None:
    try:
        check_compiler(root, lock)
        return
    except (CompilerError, WorkspaceError):
        pass

    repository = clone_repository(root, lock)
    archive = download_source(root, lock)
    source = extract_source(root, lock, archive)
    build_compiler(root, lock, repository, source)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Install or verify the GCC 2.7.2 MIPS fallback compiler."
    )
    parser.add_argument(
        "--check",
        action="store_true",
        help="verify the local fallback compiler without changing it",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        root = require_workspace_root()
        lock = load_lock(root)
        if args.check:
            clone_repository(root, lock, allow_install=False)
            check_source(root, lock)
            check_compiler(root, lock)
        else:
            install(root, lock)
    except (
        CompilerError,
        WorkspaceError,
        OSError,
        UnicodeError,
        KeyError,
        TypeError,
        ValueError,
        tarfile.TarError,
    ) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print(f"{lock['target']} GCC {lock['version']} fallback: OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
