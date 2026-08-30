#!/usr/bin/env python3

from __future__ import annotations

import re
import sys


STACK_RESTORE = re.compile(r"^\s*addu\s+\$sp,\$sp,(?P<size>\d+)\s*$")
RETURN = re.compile(r"^\s*j\s+\$31\s*$")


def normalize(lines: list[str]) -> list[str]:
    output: list[str] = []
    index = 0
    while index < len(lines):
        if index + 1 < len(lines):
            restore = STACK_RESTORE.fullmatch(lines[index].strip())
            returning = RETURN.fullmatch(lines[index + 1].strip())
            if restore is not None and returning is not None:
                output.extend(
                    (
                        "\t.set\tnoreorder\n",
                        "\t.set\tnomacro\n",
                        lines[index + 1],
                        lines[index],
                        "\t.set\tmacro\n",
                        "\t.set\treorder\n",
                    )
                )
                index += 2
                continue
        output.append(lines[index])
        index += 1
    return output


def main() -> int:
    sys.stdout.writelines(normalize(sys.stdin.readlines()))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
