#!/usr/bin/env python3

from __future__ import annotations

import argparse
import os
import sys
from pathlib import Path


DEFAULT_MAX_RSS_MIB = 2560


class MemoryGuardError(RuntimeError):
    pass


def process_status(pid: int) -> dict[str, str]:
    path = Path(f"/proc/{pid}/status")
    if not path.is_file():
        return {}
    result: dict[str, str] = {}
    for line in path.read_text(encoding="ascii", errors="replace").splitlines():
        key, separator, value = line.partition(":")
        if separator:
            result[key] = value.strip()
    return result


def process_command(pid: int) -> str:
    path = Path(f"/proc/{pid}/cmdline")
    if not path.is_file():
        return ""
    return path.read_bytes().replace(b"\0", b" ").decode(errors="replace")


def find_copilot_parent() -> int | None:
    pid = os.getppid()
    visited: set[int] = set()
    while pid > 1 and pid not in visited:
        visited.add(pid)
        status = process_status(pid)
        command = process_command(pid)
        name = status.get("Name", "")
        if (
            "github/copilot" in command
            or "@github/copilot" in command
            or name == "MainThread" and command.endswith("/copilot ")
        ):
            return pid
        try:
            pid = int(status.get("PPid", "0"))
        except ValueError:
            return None
    return None


def resident_mib(pid: int) -> float:
    value = process_status(pid).get("VmRSS")
    if value is None:
        raise MemoryGuardError(f"cannot read VmRSS for Copilot process {pid}")
    fields = value.split()
    if len(fields) != 2 or fields[1] != "kB":
        raise MemoryGuardError(f"unexpected VmRSS value: {value}")
    return int(fields[0]) / 1024


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Refuse project work when the parent Copilot CLI is near OOM."
    )
    parser.add_argument(
        "--max-rss-mib",
        type=int,
        default=int(
            os.environ.get("COPILOT_MAX_RSS_MIB", DEFAULT_MAX_RSS_MIB)
        ),
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    if args.max_rss_mib < 512:
        print("error: memory-guard limit must be at least 512 MiB", file=sys.stderr)
        return 1
    pid = find_copilot_parent()
    if pid is None:
        return 0
    try:
        rss = resident_mib(pid)
    except (MemoryGuardError, OSError, UnicodeError, ValueError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    if rss >= args.max_rss_mib:
        print(
            "error: Copilot CLI memory guard refused this command: "
            f"RSS is {rss:.0f} MiB, limit is {args.max_rss_mib} MiB. "
            "Commit or preserve the current checkpoint, start a fresh CLI "
            "session, and resume from the tracked notes.",
            file=sys.stderr,
        )
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
