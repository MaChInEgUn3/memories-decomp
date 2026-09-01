#!/usr/bin/env python3

from __future__ import annotations

import argparse
import shutil
import sys
import tarfile
from pathlib import Path, PurePosixPath

from workspace import WorkspaceError, require_workspace_root, resolve_within


class ArchiveError(RuntimeError):
    pass


def validated_members(archive: tarfile.TarFile) -> list[tarfile.TarInfo]:
    members = archive.getmembers()
    if not members:
        raise ArchiveError("retail input archive is empty")
    for member in members:
        path = PurePosixPath(member.name)
        if (
            path.is_absolute()
            or not path.parts
            or path.parts[0] != "game"
            or ".." in path.parts
        ):
            raise ArchiveError(
                f"archive member must normalize beneath game/: {member.name}"
            )
        if not (member.isdir() or member.isfile()):
            raise ArchiveError(
                f"archive links and special files are forbidden: {member.name}"
            )
    return members


def extract(root: Path, archive_path: Path) -> int:
    destination = resolve_within(root, "game")
    if destination.exists():
        raise ArchiveError("game/ already exists before archive extraction")
    extracted = 0
    with tarfile.open(archive_path, "r:*") as archive:
        members = validated_members(archive)
        for member in members:
            output = resolve_within(root, member.name)
            if member.isdir():
                output.mkdir(parents=True, exist_ok=True)
                continue
            source = archive.extractfile(member)
            if source is None:
                raise ArchiveError(f"cannot read archive member: {member.name}")
            output.parent.mkdir(parents=True, exist_ok=True)
            with source, output.open("wb") as handle:
                shutil.copyfileobj(source, handle, 1024 * 1024)
            extracted += 1
    return extracted


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Safely extract a private retail-input tar archive."
    )
    parser.add_argument(
        "archive",
        help="tar, tar.gz, tar.bz2, or tar.xz archive containing game/",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        root = require_workspace_root()
        archive = resolve_within(root, args.archive, must_exist=True)
        if not archive.is_file():
            raise ArchiveError(f"archive is not a file: {archive}")
        count = extract(root, archive)
    except (
        ArchiveError,
        WorkspaceError,
        OSError,
        tarfile.TarError,
        ValueError,
    ) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print(f"extracted {count} retail input files beneath game/")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
