# Matching Build Continuous Integration

`.github/workflows/matching-build.yml` performs a clean hosted Ubuntu build
for pushes to `master`, pull requests, and manual dispatches. It installs or
restores the pinned local tools, runs `make clean`, rebuilds the complete
PS-X EXE, and explicitly verifies:

```text
84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

## Private retail inputs

Retail files remain ignored and must never be committed. Configure these
GitHub Actions repository secrets:

| Secret | Value |
|---|---|
| `YGOFM_GAME_ARCHIVE_URL` | Private or expiring HTTPS URL for the input tar archive |
| `YGOFM_GAME_ARCHIVE_SHA256` | Lowercase SHA-256 of that exact archive |

The archive may be an uncompressed tar or use gzip, bzip2, or xz compression.
Every entry must be a regular file or directory beneath a top-level `game/`
directory. Links, devices, absolute paths, and parent-directory traversal are
rejected by `tools/project/extract_game_archive.py`.

The extracted `game/` tree must contain the same user-supplied files validated
by `make verify-inputs`, including `SLUS_014.11`, the `DATA/` files, and the
original BIN/CUE. A missing secret, download failure, archive hash mismatch,
input hash mismatch, tool failure, build failure, or rebuilt executable hash
mismatch makes the workflow fail.

GitHub does not expose repository secrets to pull requests from forks. Those
runs therefore fail at the explicit private-input check rather than receiving
retail data.
