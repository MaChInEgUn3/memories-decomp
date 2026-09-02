# Remaining Decompilation Campaign

## First evidence batch

The campaign described in `notes/remaining-decompilation-plan.md` began with
same-address collaborator evidence and the newly exposed zero-attempt
function.

### Accepted pure-C matches

| Address | Result |
|---|---|
| `0x800240B0` | Unchiga's cursor callback source matches under `gcc_2_8_1_g8_split`. Three isolated absolute C stores preserve the retail `$at` address materialization. |
| `0x80070AC0` | `AiScript_JumpEqual` matches after introducing a local AI-state pointer and updating the existing offset variable in place; the GCC register roles then match without asm. |

### Terminal refinements

| Address | Result |
|---|---|
| `0x8005C4F0` | `File_Exists` pure C remains two register-allocation words away under GCC 2.8.1. GCC 2.7.2 changes a branch displacement. Six refinements exhausted; exact inline source retained. |
| `0x8003CE74` | Pure PRNG source reaches one commutative operand-order word from retail. GCC canonicalizes both source operand orders. Six refinements exhausted; exact inline source retained. |

### Preserved partial histories

| Address | Current residual |
|---|---|
| `0x8002A788` | Exact 0x238-byte size and relocations; four dead delay-slot/scheduler words differ. Three refinement attempts remain for genuinely new scheduling evidence. |
| `0x80020BE4` | Exact 0x168-byte size; 21 words differ from store scheduling and the collaborator's removed register pin. Three canonical attempts remain. |
| `0x80050584` | Exact 0x24C-byte size; two documented register-role blocks account for 24 differing words. Four canonical attempts remain. |

### Newly exposed callback

`func_8002DDFC` received six ordinary GCC 2.8.1 G0 variants using local
assembly, GMS pseudocode, and explicit target-order labels. The closest source
is 300/304 bytes but its event-1 branch target is four instructions early.
The function is terminally deferred and remains exact assembly.

## Preserved-candidate profile sweep

`tools/project/run_remaining_profile_pass.py` tests exactly one untried
default/split/no-split profile for a preserved pure-C candidate. It is
single-worker and writes review artifacts under
`tmp/agents/remaining-profile-pass/`.

`tools/project/import_remaining_profile_results.py` imports a reviewed pass
atomically into `attempts.csv`; exact results are deliberately rejected so
they must be integrated manually.

Results:

| Pass | Tested | Exact | Nonmatch | Tool errors |
|---|---:|---:|---:|---:|
| Split | 72 | 0 | 62 | 10 |
| No-split | 71 | 0 | 71 | 0 |
| Default after explicit profiles | 9 | 0 | 9 | 0 |
| **Total** | **152** | **0** | **142** | **10** |

The tool errors are preserved evidence, mostly G8 small-data relocation
overflows or unresolved m2c pseudo-symbols. They show that those candidates
need declaration/source repair rather than another profile.

After the sweep:

- 218 unmatched game functions have terminal six-attempt deferrals;
- 145 unmatched game functions remain nonterminal;
- their canonical attempt counts are 26 at one, 44 at two, 69 at three, five
  at four, and one at five.

The sweep demonstrates that compiler split/no-split selection alone is not the
remaining blocker. Further progress must use better source structure,
declaration repair, GMS semantics, or collaborator residual notes.
