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

## Compiler installation

CI does not build GCC. It downloads the official
`gcc-2.8.1.tar.gz` asset from the `decompals/old-gcc` 0.17 release,
verifies the archive and individual `gcc`, `cc1`, and `cpp` SHA-256 hashes,
and installs a local wrapper that points the fixed-prefix release driver at
the repository-local compiler components.

The similarly named `gcc-2.8.1-psx.tar.gz` asset is not used: a complete local
comparison found 95 differing C objects and 45 text-size changes. The selected
`mips-linux-gnu` release asset reproduces the project's required GCC 2.8.1
code generation under the explicit PSX flags.

The GCC 2.7.2 fallback is a matching-research tool and is not required for the
current clean build, so CI does not install or validate it. Binutils 2.42 is
still bootstrapped locally on a cold cache and restored from the Actions cache
on later runs.

GitHub does not expose repository secrets to pull requests from forks. Those
runs therefore fail at the explicit private-input check rather than receiving
the retail executable.
