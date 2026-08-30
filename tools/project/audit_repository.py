#!/usr/bin/env python3

from __future__ import annotations

import csv
import subprocess
import sys
from pathlib import Path

from workspace import WorkspaceError, require_workspace_root


class AuditError(RuntimeError):
    pass


EXPECTED_NAME = "Copilot"
EXPECTED_EMAIL = "223556219+Copilot@users.noreply.github.com"
FORBIDDEN_TRACKED_PREFIXES = (
    "game/",
    "tmp/",
    "tools/downloads/",
    "tools/environments/",
    "tools/toolchains/",
    "tools/vendor/",
)
ATTEMPT_FIELDS = ("address", "attempt", "compiler", "flags", "result", "summary")
ATTEMPT_RESULTS = {"matched", "nonmatch", "deferred"}
MAX_FUNCTION_ATTEMPTS = 6


def git(root: Path, *arguments: str) -> str:
    try:
        result = subprocess.run(
            ["git", *arguments],
            cwd=root,
            check=True,
            text=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
    except subprocess.CalledProcessError as error:
        details = error.stderr.strip()
        message = f"git {' '.join(arguments)} failed"
        if details:
            message = f"{message}: {details}"
        raise AuditError(message) from error
    return result.stdout


def audit_identity(root: Path) -> None:
    name = git(root, "config", "--local", "user.name").strip()
    email = git(root, "config", "--local", "user.email").strip()
    if (name, email) != (EXPECTED_NAME, EXPECTED_EMAIL):
        raise AuditError(
            f"local Git identity is {name} <{email}>, expected "
            f"{EXPECTED_NAME} <{EXPECTED_EMAIL}>"
        )

    commits = [
        line for line in git(root, "rev-list", "--reverse", "HEAD").splitlines()
        if line
    ]
    if not commits:
        raise AuditError("repository has no commits")

    for commit in commits:
        output = git(
            root,
            "show",
            "-s",
            "--format=%an%n%ae%n%cn%n%ce%n%B",
            commit,
        )
        lines = output.splitlines()
        if len(lines) < 4:
            raise AuditError(f"{commit}: malformed commit metadata")
        author_name, author_email, committer_name, committer_email = lines[:4]
        message = "\n".join(lines[4:])
        if (author_name, author_email) != (EXPECTED_NAME, EXPECTED_EMAIL):
            raise AuditError(
                f"{commit}: unexpected author "
                f"{author_name} <{author_email}>"
            )
        if (committer_name, committer_email) != (
            EXPECTED_NAME,
            EXPECTED_EMAIL,
        ):
            raise AuditError(
                f"{commit}: unexpected committer "
                f"{committer_name} <{committer_email}>"
            )
        if "co-authored-by:" in message.lower():
            raise AuditError(f"{commit}: contains a Co-authored-by trailer")


def audit_tracked_paths(root: Path) -> None:
    tracked = [
        line for line in git(root, "ls-files").splitlines()
        if line
    ]
    for path in tracked:
        if path.startswith(FORBIDDEN_TRACKED_PREFIXES):
            raise AuditError(f"forbidden generated or supplied path tracked: {path}")
        if path.lower().endswith(".md") and not path.startswith("notes/"):
            raise AuditError(f"documentation is outside notes/: {path}")

    ignored = git(
        root,
        "check-ignore",
        "game/SLUS_014.11",
        "tmp/project-build/SLUS_014.11",
        "tools/environments/python/bin/python",
    ).splitlines()
    if len(ignored) != 3:
        raise AuditError("required supplied/generated paths are not all ignored")


def audit_worktree(root: Path) -> None:
    status = git(root, "status", "--porcelain").strip()
    if status:
        raise AuditError(f"worktree is not clean:\n{status}")


def parse_integer(value: str, description: str) -> int:
    try:
        return int(value, 0)
    except ValueError as error:
        raise AuditError(f"{description} is not an integer: {value}") from error


def audit_attempts(root: Path) -> None:
    functions_path = root / "config/slus_01411/functions.csv"
    attempts_path = root / "config/slus_01411/attempts.csv"

    with functions_path.open("r", encoding="utf-8", newline="") as handle:
        functions_reader = csv.DictReader(handle)
        functions = list(functions_reader)
    function_addresses = {
        parse_integer(row["address"], "function address") for row in functions
    }
    matching_addresses = {
        parse_integer(row["address"], "matching function address")
        for row in functions
        if row["status"] == "matching_c"
    }

    with attempts_path.open("r", encoding="utf-8", newline="") as handle:
        attempts_reader = csv.DictReader(handle)
        if tuple(attempts_reader.fieldnames or ()) != ATTEMPT_FIELDS:
            raise AuditError(f"{attempts_path}: unexpected CSV fields")
        attempts = list(attempts_reader)

    by_address: dict[int, list[dict[str, str]]] = {}
    for row in attempts:
        address = parse_integer(row["address"], "attempt address")
        if address not in function_addresses:
            raise AuditError(
                f"attempt references unknown function {address:#010x}"
            )
        if row["result"] not in ATTEMPT_RESULTS:
            raise AuditError(
                f"{address:#010x}: unsupported attempt result {row['result']}"
            )
        if not row["compiler"] or not row["flags"] or not row["summary"]:
            raise AuditError(f"{address:#010x}: incomplete attempt record")
        by_address.setdefault(address, []).append(row)

    matched_attempts: set[int] = set()
    for address, rows in by_address.items():
        if len(rows) > MAX_FUNCTION_ATTEMPTS:
            raise AuditError(
                f"{address:#010x}: exceeds six-attempt budget"
            )
        ended = False
        for expected, row in enumerate(rows, start=1):
            attempt = parse_integer(row["attempt"], "attempt number")
            if attempt != expected:
                raise AuditError(
                    f"{address:#010x}: expected attempt {expected}, "
                    f"found {attempt}"
                )
            if ended:
                raise AuditError(
                    f"{address:#010x}: attempt recorded after terminal result"
                )
            if row["result"] == "matched":
                matched_attempts.add(address)
                ended = True
            elif row["result"] == "deferred":
                ended = True

    missing = sorted(matching_addresses - matched_attempts)
    if missing:
        formatted = ", ".join(f"{address:#010x}" for address in missing)
        raise AuditError(f"matching C functions lack successful attempts: {formatted}")


def main() -> int:
    try:
        root = require_workspace_root()
        audit_identity(root)
        audit_tracked_paths(root)
        audit_attempts(root)
        audit_worktree(root)
    except (
        AuditError,
        WorkspaceError,
        OSError,
        UnicodeError,
        KeyError,
        TypeError,
        csv.Error,
    ) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print("repository audit: OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
