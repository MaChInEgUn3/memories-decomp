# Remaining Game Decompilation Plan

## Starting state

The resident inventory contains 1,794 functions:

| Category | Count |
|---|---:|
| Game functions | 1,196 |
| Psy-Q CRT/SDK functions | 598 |
| Matching-C game functions | 769 |
| Matching sources still containing GCC inline assembly | 80 |
| Game functions still represented by assembly | 427 |
| Assembly functions already deferred after six attempts | 217 |
| Assembly functions with remaining canonical budget | 209 |
| Newly exposed zero-attempt game functions | 1 |

The zero-attempt function is `func_8002DDFC`, a game callback recovered after
the original first-pass campaign.

## Non-negotiable rules

- Never decompile the 598 Psy-Q CRT/SDK functions.
- Try GCC 2.8.1 with MASPSX 2.81 first.
- Use GCC 2.7.2 with MASPSX 2.72 only when code evidence supports the DOS
  cohort or the 2.8.1 budget is exhausted.
- Never exceed six distinct source variants for one function.
- Record every variant and mismatch reason immediately.
- Keep exact assembly for any function that reaches attempt six without a
  match.
- Treat GMS, Unchiga's decomp, and Unchiga's recomp as evidence, not ground
  truth. Do not copy their guessed types.
- Run matching work sequentially; `make` may use two jobs.
- Keep all work inside this repository and all generated candidates/logs under
  `tmp/`.
- Keep commits atomic and push accumulated commits only when about 15 minutes
  have elapsed; never wait idly for the push interval.

## Phase 1: recover recorded collaborator matches

Re-audit Unchiga's `match/attempts/*.json` and `match/matched/*.c` against the
current project.

Priority order:

1. Recorded zero-difference results.
2. Results with fewer than 10 differing words.
3. Results with fewer than 25% differing words.
4. Larger structural sketches only when their comments identify a concrete
   residual and a remaining source variant.

Do not rerun Unchiga's exhaustive `msearch.py` cross-products. They can contain
hundreds or thousands of variants and would violate this project's six-variant
limit. Extract only the recorded winner or closest source shape, then verify it
once with the local toolchain.

An exact linked-byte candidate may use a C integer address for an isolated
absolute store when symbolic C changes register allocation. Such a candidate
is acceptable only when:

- it is pure C;
- the literal equals the locally verified target symbol address;
- complete function bytes match;
- all remaining symbolic relocations match;
- the exception is recorded in the attempt summary and source note;
- the complete executable matches after integration.

## Phase 2: collaborator near-match pass

There are currently 49 relevant Unchiga sketch addresses:

- 23 unmatched functions with canonical budget remaining;
- 26 matching inline-assembly functions with refinement budget remaining.

For each address:

1. Read the recorded best flags, knob count, and residual word count.
2. Recover the exact recorded best source without executing a broad search.
3. Replace reference declarations with independently checked local widths,
   signedness, and prototypes.
4. Compile one candidate under the recorded profile.
5. If it fails, use at most one additional variant justified by the recorded
   residual notes.
6. Record and stop when the per-function budget is exhausted.

## Phase 3: zero-attempt callback

Attempt `func_8002DDFC` from:

- its local target assembly;
- GMS pseudocode at the same address;
- the call contract in `func_8002DF2C`;
- neighboring matching object-callback structures.

This function must receive an ordinary first attempt before the campaign can
be considered complete.

## Phase 4: inline-assembly replacement

For the 80 matching sources that still use GCC assembly:

1. Prefer a recorded Unchiga pure-C or sketch result.
2. Use GMS pseudocode only for control-flow and role clues.
3. Preserve current matching sources until a pure-C candidate independently
   matches.
4. Continue `inline_refinement` histories within their remaining budget.
5. Leave irreducible low-level routines in their current exact form after
   attempt six, with the residual documented.

## Phase 5: remaining canonical functions

Process the 209 nonterminal assembly functions in evidence order:

1. Same-address Unchiga sketch or source.
2. Same-address GMS pseudocode.
3. Recomp live behavior or QoL instrumentation.
4. Existing `ygofm-decomp` structural reference.
5. Local matching siblings and callers.
6. Fresh m2c-assisted reconstruction when no external body exists.

Favor smaller functions and complete subsystem chains, but do not skip a large
function with unusually strong same-address evidence.

## Decompilation completion gate

The matching phase is complete only when every game function is in one of
these states:

- exact matching C;
- exact current matching source with a terminal inline-refinement history;
- assembly fallback with a terminal six-attempt history;
- documented intentional handwritten assembly.

At that point, regenerate progress and publish a report containing accepted
matches, pure-C replacements, new deferrals, and remaining intentional
assembly.

## Post-decompilation phases

Only after the completion gate:

1. Apply evidence-backed semantic names using local behavior, GMS, DOTR style,
   and Unchiga's live research.
2. Regroup newly understood contiguous same-profile functions into subsystem
   translation units.
3. Build a cross-function global-use map from matching C and target assembly.
4. Define shared structures only where multiple independently matched
   functions establish compatible offsets, widths, and roles.

Do not begin the global-use/structure phase while active matching candidates
remain.
