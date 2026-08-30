#!/usr/bin/env python3

from __future__ import annotations

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


def main() -> int:
    try:
        root = require_workspace_root()
        audit_identity(root)
        audit_tracked_paths(root)
        audit_worktree(root)
    except (AuditError, WorkspaceError, OSError, UnicodeError) as error:
        print(f"error: {error}", file=sys.stderr)
        return 1
    print("repository audit: OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
