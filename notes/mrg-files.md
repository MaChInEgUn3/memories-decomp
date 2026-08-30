# MRG File Model

## Current understanding

The project does not treat `*.MRG` as self-describing archive formats.
According to the user-supplied research, the original build scripts **merged**
input files by concatenation and generated offsets that were compiled into a C
header or equivalent source table.

`WA_MRG.MRG` is the leading hypothesis for the runtime overlays loaded into the
high-memory slots documented in `notes/memory-map.md`. This remains a hypothesis
until compiled offset tables and load calls are tied to specific WA_MRG byte
ranges.

Consequences:

- Do not infer an archive header merely because the first words resemble
  offsets or counts.
- The authoritative index is expected in executable data tables and the code
  that issues file seeks/reads.
- Inner file boundaries must be recovered from compiled offset/size arrays,
  access functions, and validation against the concatenated bytes.
- Different MRG files may use different generated tables even though the
  container operation was the same.
- Repacking requires reproducing both concatenation order and generated
  compile-time offsets; editing only the MRG bytes is insufficient.

## Relevant files

- `game/DATA/SU.MRG`
- `game/DATA/WA_MRG.MRG`
- `game/DATA/MODEL.MRG`

The executable also preserves development paths such as:

```text
M:/mrgSU/SU.mrg
M:/mrgSU/model.mrg
```

These strings support a merge-script workflow and may help identify the source
module responsible for generated offset tables.

## Investigation workflow

1. Find all code and data references associated with each MRG filename.
2. Prioritize `WA_MRG.MRG` references that target overlay slot addresses such
   as `0x8013A000`, `0x80146000`, `0x80168000`, or `0x80180000`.
3. Identify the seek/read routine arguments and the tables supplying offsets
   and lengths.
4. Classify table element widths, sentinels, alignment, and whether lengths are
   explicit or derived from the next offset.
5. Verify every proposed boundary against the MRG bytes.
6. Record recovered entries and evidence under `notes/`; keep transient
   extraction output under `tmp/`.
7. Only create extraction/repacking tools when executable analysis requires
   them, because asset-format reversal remains outside the primary executable
   matching target.

The tracked disc LBA manifest identifies each complete MRG file's ISO extent.
Those LBAs are separate from the generated offsets of items inside each merged
file.
