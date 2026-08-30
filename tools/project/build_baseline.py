#!/usr/bin/env python3

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path

from workspace import (
    WorkspaceError,
    local_environment,
    require_workspace_root,
    resolve_within,
)


class BuildError(RuntimeError):
    pass


TOOLCHAIN = "tools/toolchains/binutils-2.42/bin"
OBJECT_DIRECTORY = "tmp/project-build/obj"


def run(root: Path, command: list[str]) -> None:
    environment = os.environ.copy()
    environment.update(local_environment(root))
    try:
        subprocess.run(
            command,
            cwd=root,
            env=environment,
            check=True,
        )
    except subprocess.CalledProcessError as error:
        raise BuildError(
            f"command failed with exit code {error.returncode}: {command[0]}"
        ) from error


def tool(root: Path, name: str) -> Path:
    path = resolve_within(root, f"{TOOLCHAIN}/mipsel-none-elf-{name}", must_exist=True)
    if not path.is_file():
        raise BuildError(f"required tool is not a file: {path}")
    return path


def require_generated_file(root: Path, relative_path: str) -> Path:
    path = resolve_within(root, relative_path, must_exist=True)
    if not path.is_file():
        raise BuildError(f"required generated input is not a file: {relative_path}")
    return path


def assemble(
    root: Path,
    assembler: Path,
    source_path: str,
    output_path: str,
) -> Path:
    source = require_generated_file(root, source_path)
    output = resolve_within(root, output_path)
    output.parent.mkdir(parents=True, exist_ok=True)
    include_directory = resolve_within(root, "tmp/splat/include", must_exist=True)
    run(
        root,
        [
            str(assembler),
            "-EL",
            "-march=r3000",
            "-mabi=32",
            "-G0",
            "-I",
            str(include_directory),
            "-o",
            str(output),
            str(source),
        ],
    )
    return output


def binary_object(
    root: Path,
    objcopy: Path,
    source_path: str,
    output_path: str,
) -> Path:
    source = require_generated_file(root, source_path)
    output = resolve_within(root, output_path)
    output.parent.mkdir(parents=True, exist_ok=True)
    run(
        root,
        [
            str(objcopy),
            "-I",
            "binary",
            "-O",
            "elf32-littlemips",
            "-B",
            "mips",
            str(source),
            str(output),
        ],
    )
    return output


def build(root: Path) -> Path:
    assembler = tool(root, "as")
    linker = tool(root, "ld")
    objcopy = tool(root, "objcopy")

    objects = [
        assemble(
            root,
            assembler,
            "tmp/splat/asm/header.s",
            f"{OBJECT_DIRECTORY}/header.o",
        ),
        assemble(
            root,
            assembler,
            "tmp/splat/asm/data/initial_data.data.s",
            f"{OBJECT_DIRECTORY}/initial_data.o",
        ),
        assemble(
            root,
            assembler,
            "tmp/splat/asm/entry.s",
            f"{OBJECT_DIRECTORY}/text.o",
        ),
        assemble(
            root,
            assembler,
            "tmp/splat/asm/data/initialized_data.data.s",
            f"{OBJECT_DIRECTORY}/initialized_data.o",
        ),
        binary_object(
            root,
            objcopy,
            "tmp/splat/assets/bss_image.bin",
            f"{OBJECT_DIRECTORY}/bss_image.o",
        ),
        binary_object(
            root,
            objcopy,
            "tmp/splat/assets/reserved_zero.bin",
            f"{OBJECT_DIRECTORY}/reserved_zero.o",
        ),
        binary_object(
            root,
            objcopy,
            "tmp/splat/assets/overlay_slots.bin",
            f"{OBJECT_DIRECTORY}/overlay_slots.o",
        ),
        binary_object(
            root,
            objcopy,
            "tmp/splat/assets/tail_data.bin",
            f"{OBJECT_DIRECTORY}/tail_data.o",
        ),
    ]

    linker_script = resolve_within(
        root, "linker/slus_01411.ld", must_exist=True
    )
    output_elf = resolve_within(root, "tmp/project-build/SLUS_014.11.elf")
    output_map = resolve_within(root, "tmp/project-build/SLUS_014.11.map")
    output_exe = resolve_within(root, "tmp/project-build/SLUS_014.11")

    run(
        root,
        [
            str(linker),
            "-EL",
            "-G0",
            "--no-relax",
            "--no-warn-rwx-segments",
            "-T",
            str(linker_script),
            "-Map",
            str(output_map),
            "-o",
            str(output_elf),
            *[str(path) for path in objects],
        ],
    )
    run(
        root,
        [
            str(objcopy),
            "-O",
            "binary",
            str(output_elf),
            str(output_exe),
        ],
    )

    expected_size = 0x1D0800
    actual_size = output_exe.stat().st_size
    if actual_size != expected_size:
        raise BuildError(
            f"rebuilt executable is {actual_size:#x} bytes, expected {expected_size:#x}"
        )
    return output_exe


def main() -> int:
    try:
        root = require_workspace_root()
        output = build(root)
    except (BuildError, WorkspaceError, OSError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print(f"built: {output.relative_to(root)}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
