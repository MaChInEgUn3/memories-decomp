# Matching Build Continuous Integration

`.github/workflows/matching-build.yml` performs a clean hosted Ubuntu build
for pushes to `master`, pull requests, and manual dispatches. It installs or
restores the pinned local tools, runs `make clean`, rebuilds the complete
PS-X EXE, and explicitly verifies:

```text
84a54ed74f3d0edd6d81380839f7e4ef5bfb21ecea18be9a062bd6bfa5a45c88
```

## Private retail executable

Retail files remain ignored and must never be committed. Upload only your
verified `game/SLUS_014.11` to a private location that provides a direct HTTPS
download, then configure this GitHub Actions repository secret:

| Secret | Value |
|---|---|
| `YGOFM_SLUS_01411_URL` | Private or expiring direct-download URL for `SLUS_014.11` |

The workflow writes that response to `game/SLUS_014.11` and checks it against
the known retail SHA-256 before installing tools or building. No DATA files,
MRG files, STR/XA files, or BIN/CUE are uploaded to CI.

Normal matching-build targets use `make verify-target`, which validates only
the executable. Disc-analysis and full repository-audit targets continue to
use `make verify-inputs`, so local LBA and extracted-data verification remains
unchanged.

A missing secret, download failure, input hash mismatch, tool failure, build
failure, or rebuilt executable hash mismatch makes the workflow fail.

GitHub does not expose repository secrets to pull requests from forks. Those
runs therefore fail at the explicit private-input check rather than receiving
the retail executable.
