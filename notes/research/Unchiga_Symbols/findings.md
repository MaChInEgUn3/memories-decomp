# Live-trace findings — names pending operator approval

Every entry here was observed LIVE in the recomp (fn-entry trace + RAM
snapshots + injected input), with the evidence stated. Nothing is applied to
the build until its row says APPROVED and the name survives the byte-verify
pipeline. Status: PENDING / APPLIED / REJECTED / HOLD. Operator policy 2026-08-31:
apply solid names directly; operator corrects when needed.

## Session 2026-08-31 — main menu, up/down only

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F1 | `0x80184594` (1 byte) | Main-menu cursor. Read live: 0=NEW GAME, 1=LOAD, 2=2P DUEL, 3=TRADE, 4=OPTION; +1 per down, -1 per up, wraps both directions. Lives in the loaded menu module's data, so it may be the shared cursor of every module-driven menu (open question — re-check in other menus). Currently `menuSelection` (idb2018; RAM map "Menu ID"). | `g_MenuCursor` | APPLIED |
| F2 | `func_80048658(id, vol)` | Plays a sound effect: called with (6, 0xFF) on every cursor move — SE #6 is the menu blip; chain reaches `_spu_note2pitch` / `SpuGetVoiceEnvelope`. Existing wrappers `call_80048658_255_0`/`call_80048658_flagged` fit "play SE id at volume". DotR vocabulary for this role: `SD_SEPlay*`. | `SD_SEPlay` | APPLIED |
| F3 | `func_800482B0(id, 0, vol)` | SE playback internal, called by the F2 chain (ra 0x80048758). | (hold — internals need one more session) | HOLD |
| F4 | `func_8004803C(id, 0, 0)` | SE playback internal, deeper in the same chain (ra 0x800484E8). | (hold) | HOLD |
| F5 | `func_80040410(obj, state)` | Widget/object state setter: writes `obj+0x69 = state`, clears bit 0x10 of flags at `obj+8` (matched C). Called twice per cursor move on the two highlight widgets (0x800F0698 / 0x800F0858) with swapped states. | (hold — want the widget pool named first) | HOLD |
| F6 | `func_80041C8C(obj, dataPtr, state<<24)` | Per-widget visual refresh after F5; still unmatched (19/53 near-miss stub). | (hold) | HOLD |

### OPTION round-trip additions (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F7 | `0x8002D6C8` `optionsMenuLoop` | LIVE-CONFIRMED: it is the ambient mode loop while sitting in the OPTION screen. First live validation of the idb2018 loop-family names. | (keep `optionsMenuLoop`) | CONFIRMED |
| F8 | `SD_SEPlay` ids | SE 6 = cursor move, SE 7 = confirm (X), SE 8 = cancel (Circle); all at vol 0xFF. | (fact, no name) | CONFIRMED |
| F9 | `g_MenuCursor` scope | During the whole OPTION visit the byte stayed 4 (the slot we entered from) and the menu module at 0x80180000 was NOT reloaded (arena md5 stable). The OPTION screen keeps its own selection state elsewhere. | (name unchanged) | CONFIRMED |

### STEREO/MONO toggle (same session, OPTION screen)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F10 | `func_80046FA0(mode)` | Fired on every stereo/mono toggle with a0=0 (STEREO) / a0=1 (MONO), both directions. Matched body: writes soundState(D_8009B45C)->f48, toggles flag 0x815, re-derives CD volume via func_80044DC0. Exact DotR vocabulary for this role. | `SD_SetOutputType` | APPLIED |
| F11 | `0x8009B408` (byte) | Flips 0<->1 with the setting (0=STEREO, 1=MONO), live, both directions, stable across double-checks. func_8003C628 derives D_8009B37D from it (sign-bit = reset semantics), so this is the authoritative stored setting. | `g_SoundMode` | APPLIED |
| F12 | `0x8003FEE0(id)` | Observed twice with different ids (8 = cancel, 0x2F = option toggle): body always calls SD_SEPlay(id, 0xFF). Current fleet name `call_80048658_255_0` is factually wrong about the args. | `SD_SEPlayFull` | APPLIED |
| F13 | `SD_SEPlay` id 0x2F | The option-toggle blip (vol 0xFF), via SD_SEPlayFull. | (fact) | CONFIRMED |
| F14 | `select_sound_preset` (0x800171A8) | Did NOT fire during stereo/mono toggling — it is NOT the output-type setter (kills the earlier SD_SetOutputType hunch for it). | (null result) | CONFIRMED |

### TRADE memory-card flow (same session, one card only)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F15 | `mainMenuLoop` modality | The 1P/2P MEMORY CARD caution dialog, BEGIN LOAD, slot-1 load, slot-2 NO DATA and its dismissal ALL run inside `mainMenuLoop` (ambient through every phase). Menu dialogs are modals, not mode switches. | (architecture fact) | CONFIRMED |
| F16 | `0x8002D7CC` (tradeLoop conflict) | Never fired during the whole card flow -- the trade screen proper requires BOTH cards to load. Conflict stays open; we now know its precondition. | (null result) | CONFIRMED |

### LOAD flow + secondary menu (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F17 | secondary menu mode | The post-load menu (CAMPAIGN/FREE DUEL/BUILD DECK/LIBRARY/PASSWORD/SAVE) runs in the SAME mode as the main menu: `mainMenuLoop` ambient, mode byte 0x8009B26C unchanged (0xC8 -> low 5 bits = 8 = mainMenuLoop's slot in `D_80090B64[]`). The menu module swaps layouts, not modes. | (architecture fact) | CONFIRMED |
| F18 | `g_MenuCursor` continuation | In the secondary menu, hovering the TOP item (CAMPAIGN) reads cursor = 5 — the shared cursor continues past the main menu's 0-4. PROVEN: SAVE (bottom item) reads cursor=10, so the secondary menu occupies indices 5-10 (CAMPAIGN=5 .. SAVE=10) of the shared cursor. | (fact) | CONFIRMED |
| F19 | save block liveness | Direct read after load: starchips=5, sorted 40-card deck, trunk = 722 distinct / 2166 total (3x every card — an all-cards save). The RAM map's 0x801D02xx-07xx block is the LIVE save state. The load itself produced a zero-byte RAM diff because the same save was already resident (loaded during the earlier TRADE slot-1 read). | (fact) | CONFIRMED |
| F20 | yes/no + LOAD COMPLETE dialogs | Both are `mainMenuLoop` modals, dismissed by X, consistent with F15. | (fact) | CONFIRMED |

### SAVE flow (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F21 | save write path | X -> save? -> X -> overwrite? -> X -> SAVE COMPLETE, all `mainMenuLoop` modals (mode 0xC8 throughout). The card write really ran: 5,952 write events captured via the recomp's card tracker, pumped by BIOS-kernel code reading from a staging image around `0x801DC383+`. The write-phase function cluster is preserved in tmp/save_session.json. | (facts) | CONFIRMED |
| F22 | `0x801D3xxx` region | ~78 bytes changed there during the save (the only non-display churn near the save block) — likely save metadata/checksum staging. | (suspect lead) | CONFIRMED-OBSERVED |

### PASSWORD screen (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F23 | `0x8002D684` | CONFLICT ADJUDICATED: it is the ambient mode loop of the password screen (live). The IDB's `passwordMenuLoop` is correct; our `mask_test_call_800eb26c` was the mechanical read of the same loop. Rename queued for the bulk pass. | `passwordMenuLoop` | APPLIED |
| F24 | mode indices | Entering PASSWORD switched the mode byte 0xC8 -> 0xCA — a REAL mode change (unlike every dialog so far). Mode-table indices measured: 8 = main/secondary menu, 10 = password screen. | (fact) | CONFIRMED |
| F25 | `0x8016D410` | The password entry digits: 8 bytes, one per digit (value 0-9), first digit at +0. Proven by reversible up/down spins (0->1->2->0). Lives in the password screen's own loaded module (~0x8016xxxx arena — another disc-loaded screen module, sibling of the menu module at 0x80180000). | `g_PasswordDigits` | APPLIED |
| F26 | screen facts | 8-digit entry field, starchip balance displayed from the save block, X=OK / Circle=END. Cursor at PASSWORD menu item read 9, completing the 5-10 proof. | (facts) | CONFIRMED |

### PASSWORD validation (same session, Blue-Eyes 89631139 entered)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F27 | validation split | X on 00000000: nothing but the SE chain fires — rejection is internal to the password module, no EXE lookup visible, no dialog. X on a real password: a 104-function pipeline runs — the CD request layer fires (later shown by F33 to be the ambient heartbeat, not an art fetch: pane art is RAM-resident), widget spawns build the card pane, `int_to_digits` renders the 999999 cost. Card shown, EXCHANGE/QUIT offered, starchips untouched until exchange. | (facts) | CONFIRMED |
| F28 | `int_to_digits` | Live-confirmed in its named role: fired exactly when the cost number appeared on screen. | (keep name) | CONFIRMED |
| F29 | `func_80013C28` | Second sighting: fired during OPTION screen build AND during card-art reveal — both disc-load moments. The screen-transition hypothesis is dead; it belongs to the CD streaming path. | (suspect refined) | CONFIRMED-OBSERVED |

### EXCHANGE refusal (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F30 | insufficient-funds path | X on EXCHANGE with 5 < 999999 starchips: silent refusal — zero new EXE functions beyond an SPU poll, no dialog, starchips and trunk byte-verified untouched. The affordability check is inside the password module; the real purchase path (deduct + trunk increment) remains untraced. NOTE: on this all-cards x3 save, even an affordable purchase may refuse at the copy cap, so tracing a successful exchange likely needs a different save. | (facts) | CONFIRMED |

### PASSWORD deep dive (99999-starchip session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F31 | purchase path | Bought card 2 (Mystical Elf, pw 15025844, cost 160), byte-exact: starchips 99999->99839, trunk[card] 3->4 (no 3-copy cap on trunk), used-flag set, acquisition logged. ONE-TIME USE CONFIRMED: re-entry rejected with "already put in that password" (operator-witnessed). | (facts) | CONFIRMED |
| F32 | `g_LastCardDrops` | On purchase the list SHIFTED with card 2 inserted at the front — it is really the last-10 cards ACQUIRED (drops and password buys both). Description upgrade queued. | (semantic fix) | CONFIRMED |
| F33 | card art source | Zero CD reads during any reveal — the card art is RAM-resident. The earlier "disc streaming" attribution was a false positive: those functions are the periodic CD heartbeat (12-byte reads at LBA 9730), which also poisoned a reveal-detection marker this session. Instrument lesson: never use heartbeat members as event markers. | (facts) | CONFIRMED |
| F34 | digit cursor sprite | LEFT/RIGHT moves an X-coordinate pair at 0x8009B510/0x8009B518 (+24px per digit cell, echoed into packed sprite data ~0x800CBBxx). Each animation tick, the widget fn at ~0x80042210/20 builds the sprite record in the SCRATCHPAD (0x1F800320) and draws it via GsSortFlipSprite — the "rotation" is flip-frame animation. | (mechanism) | CONFIRMED |
| F35 | `0x801D0698` | 0 -> 0x20 exactly on the purchase; with F31's rejection, this is the used-password flag store (bit mapping/extent still unmapped). Cost-10 table rows were rejected with virgin flags — those cards look non-passwordable (separate mechanism, open). | used-password flags | CONFIRMED-OBSERVED |

### LIBRARY card view (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F36 | `libraryMenuLoop` | Live-confirmed ambient in the Library (third loop validated). Library = mode slot 4 (0xC8 -> 0xC4 on entry); the card-detail view is a MODAL within it (mode unchanged). The grid cursor is NOT g_MenuCursor (menu value persists) — see F40: it is the global `selectedCardId`. | (keep name) | CONFIRMED |
| F37 | card art, two paths | The library card view streams from disc: ~392 real 2048-byte sector reads (LBA ~28534) into staging at 0x8012C800-0x8013F800 and 0x801A8000 (that arena doubles as a general load buffer). The password screen's smaller art pane used NO disc reads. Full art = disc; pane art = RAM-resident. | (facts) | CONFIRMED |
| F38 | shared card-display core | 81 functions run in BOTH card displays: the CD request layer (func_800137E4/13940/13998/13C28/1455C + the unnamed libcd text_* stack, DsPacket, CdGetSector, parcpy/rescpy), the widget constructors (find_free_slot_0x10_0x60, init_obj_id_pos_flags, init_container_entry_objs...), GsSortPoly for the art quad, and the SE plays. This is "draw a card" as a family. | (family map) | CONFIRMED |
| F39 | library-view-only cluster | 53 functions unique to the detail view — including the 0x80035AB8-0x80039xxx group that renders the description TEXT (password view shows no description) and the 0x8002A6B8-0x8002B194 widgets (stars, guardian-star icons). The text-engine hunt starts here. | (lead) | CONFIRMED-OBSERVED |

### LIBRARY grid scroll (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F40 | `selectedCardId` (0x8009B338) | LIVE-CONFIRMED as the library grid cursor: 1->2->3 on RIGHT, +10 on DOWN (10-wide grid), fully reversible. It holds the selected card's ID (1-based) — the idb2018 name validated in its natural habitat. | (keep name) | CONFIRMED |
| F41 | `0x8009B258/59` (2 bytes) | Packed grid coordinates: low byte = column (+1 per RIGHT), high byte = row (+1 per DOWN), both reversible. Scope (library-only vs shared card-grid widget) unverified — check in Build Deck before naming. | `g_GridCursorCol/Row` | APPLIED |
| F42 | `0x801D5608` | Mirrors the selected card id exactly (1->11->1). This is the RAM map's "? (used in function 0x21598/calcRankScore)" row — a current-card context copy shared with the rank scorer's output area. | (suspect refined) | CONFIRMED-OBSERVED |

### LIBRARY navigation model (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F43 | grid navigation decoded | The "8 sections" are pure rendering — no section variable exists. State is just (col, row, selectedCardId): `g_GridCursorCol` spans BOTH panels 0-19 (right panel = cols 10-19 showing the next hundred), `g_GridCursorRow` counts ABSOLUTELY (9 -> 10 crossing the view boundary, not capped). Measured: RIGHT from card 10 -> 101 (col 9->10); RIGHT at col 19 snakes to next row (110 -> 11); DOWN at the bottom row scrolls the view a full two-panel block (100 -> 210, row 9 -> 10). Sections tile 2 columns x 4 rows (operator-confirmed): section = (row/10)*2 + (col>=10), sel = section*100 + (row%10)*10 + (col%10) + 1 — reproduces every measured move. | (facts; names already applied) | CONFIRMED |
| F44 | `0x8009B35A`, `0x800ECE7C/98` | Additional bytes tracking the view scroll (display-offset counters near the selection globals). | (suspects) | CONFIRMED-OBSERVED |

### LIBRARY 3D monster viewer (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F45 | card-page load | Opening a card's detail page streams ~392 sectors from a per-card disc location (card 1: LBA 28534, card 101: LBA 56134) into the standard staging (0x8012Fxxx-0x8013Fxxx + 0x801A8000). The red arrow appears when the load completes; SQUARE then opens the 3D viewer with ZERO additional disc access — art and monster model arrive in the same load. | (facts) | CONFIRMED |
| F46 | 3D viewer family | 105-function ambient set while the model rotates: the full GTE matrix stack (MulMatrix, Push/PopMatrix, RotMatrix*_gte), `rsin`/`rcos`/`ratan2` driving the orbiting camera via `GsSetRefView2`, hierarchical model render through `GsSortUnit`/`GsGetLwsUnit`, lighting, `RCpolyFT4A` rasterization — plus 54 unnamed functions that ARE the model/animation layer (prime naming ground). The `D_800F2C40` slot pollers run here too (likely the emote's monster-cry SE). | (family map) | CONFIRMED |
| F47 | `maybe_loadMonsterModel` (0x80056504) | Did NOT fire anywhere in the library model path — its hedge stays. The IDB name likely refers to the DUEL-side loader that fills `playerMonModel`/`enemyMonModel` (0x80100000/0x80140000), a separate path. `func_80013C28` third sighting: fired with (channel=1, record 0x800F5DB0) — confirmed CD stream request member. | (negative + refinement) | CONFIRMED |

### BUILD DECK — trunk sorting (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F48 | `buildDeckMenuLoop` | Live-confirmed ambient (fourth loop validated). Build Deck = mode slot 7 (0xC8 -> 0xC7). | (keep name) | CONFIRMED |
| F49 | trunk sort mechanism | START cycles 7 sort modes. Each mode's order is computed ONCE via PsyQ `qsort(0x80100004, 722, 16, cmp)` then CACHED (14 presses total -> exactly 6 computed sorts, one per non-default mode). The trunk VIEW is 722 x 16-byte records in the 0x80100000 scratch arena (the "playerMonModel" buffer moonlighting). One comparator serves every mode: `0x80032BD4`, a mode-dispatching comparator; `compDeckCard` fires beneath it only on the name-ordered modes (576/133 calls observed). CORRECTED by F57: the qsort call cascade is quicksort's own recursion, and the comparator story is two siblings, not one dispatcher. | (superseded detail) | CONFIRMED |
| F50 | sort-mode variable | Not yet pinned — no byte cycled cleanly 0-6 across presses; likely a free-running press counter used mod 7, or module-held state. Open. | (open) | HOLD |

### BUILD DECK — chest list navigation (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F51 | list navigation mechanics | The chest list shows 8 rows. DOWN/UP move the highlight within the window; R1/L1 scroll a full page (+/-8); R2/L2 skip chunks of +/-50. All reversible, verified at 351 Yaranzo. | (facts) | CONFIRMED |
| F52 | `selectedCardId` in build deck | Here it tracks the BOTTOM VISIBLE row of the window (358 while the cursor sat on 351 at top; +8 per R1 page, +50 per R2 chunk, unchanged by in-window cursor moves). Same global, different role per screen: grid cursor in the library, window edge in the chest list. | (role note) | CONFIRMED |
| F53 | `g_GridCursorCol/Row` scope | The pair does NOT move during chest-list navigation — it belongs to card GRIDS (library-style), not lists. Scope question from F41 answered. | (scope answer) | CONFIRMED |
| F54 | list cursor variable | Authoritative storage not pinned (render-side derivatives at 0x800A0609/0A, 0x800F073A, 0x8009B0B6 lag by a step; pointer hunt found only stack transients). Likely module-held. Open, alongside the sort-mode variable (F50). | (open) | HOLD |

### BUILD DECK — deck pane (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F55 | deck pane navigation | Same mechanics as the chest list: 8 visible rows, in-window cursor moves leave `selectedCardId` alone; page/chunk scrolls update it to the BOTTOM VISIBLE row's card id (verified against the screenshot: sel=145 = the bottom row "The Bewitching P."). F52's role reading confirmed on a second list. | (facts) | CONFIRMED |
| F56 | `0x8009B0AC` | Flipped on the chest->deck pane switch (1->0), and previously on the library's left->right panel crossing (0->1). Two sightings as an active-pane indicator; polarity semantics unconfirmed. | `g_ActivePane` (suspect) | HOLD |

### BUILD DECK — deck sorting (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F57 | deck sort + comparator model | The deck view sorts at 0x80102D50 (40 x 16B records) and RE-SORTS on nearly every START (unlike the trunk's cached orders). Two comparators observed across the mode cycle: `compDeckCard` (0x80032B60) for three consecutive modes, `compare_rec_two_level_std` (0x80032BD4) for the others — both generic two-level record comparators with nameKeys tie-breaks (fleet-matched bodies agree). So each mode REBUILDS the records' primary keys and picks a comparator flavor; the earlier "mode-dispatching comparator" and "two-level CARD TYPE sort" readings in F49 are corrected — the observed qsort cascades are quicksort recursion. | (model) | CONFIRMED |

### BUILD DECK — card moves (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F58 | deck editing is staged | X on a deck card removed it (40->39), X on a trunk card added it (39->40) — but `playerDeck` in the save block stayed byte-identical through BOTH edits. Editing works on staged/view state; the save-block deck must be committed on screen exit (verify when leaving). The trunk rows' in-deck count column updates live. | (edit-buffer model) | CONFIRMED |
| F59 | `0x801D560C` | The working deck count (40->39->40 in lockstep with the edits), sitting in the 0x801D5608 current-context block right after the selected-card mirror. View copy at 0x80105AA0. | `deckCount` (working) — suspect | HOLD |

### BUILD DECK — restore & exit (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F60 | edit-repair + exit | The accidental double-registers (3-frame presses double-fire on EDIT actions — instrument lesson; 2-frame pulses register once) were fully repaired: both stray Yaranzos removed, cards 9 and 58 re-added, staged deck verified EXACTLY equal to the original multiset. Exit (Circle) captured: cancel blip, teardown family, mode back to 8. Because the staged deck equaled the original, the commit wrote identical bytes — the F58 commit-on-exit hypothesis stays OPEN for a run with a genuinely changed deck. One commit-path lead: on exit, buildDeckMenuLoop's body called `call_80047430_neg8_0` with a SAVE-BLOCK pointer (0x801D07DA, 0x10). Full exit set in tmp/bd_exit.json. | (facts + lead) | CONFIRMED |
| F61 | trunk "New!" tag | CORRECTED by operator: New! marks cards you LAST WON (recently acquired, list holds ~15-16) — not returned cards. Ties to the last-acquired list (g_LastCardDrops region; capacity may exceed the RAM map's 10 entries — verify extent). NEW sort mode presumably surfaces these. | (fact, operator-corrected) | CONFIRMED |

### BUILD DECK — deck-ready guard (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F62 | exit guard | Circle with the working deck count != 40 opens the "YOUR DECK ISN'T READY!" modal (BUILD DECK / EXIT) INSTEAD of exiting — mode byte stays 0xC7, so it's another in-mode modal. The guard reads the working count (0x801D560C), not the save block. Capture in tmp/notready.json. | (fact) | CONFIRMED |

### FREE DUEL menu (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F63 | `freeDuelMenuLoop` | Live-confirmed ambient (fifth loop validated). Free Duel = mode slot 6 (0xC8 -> 0xC6); the SELECT OPPONENT! dialog is another in-mode modal. | (keep name) | CONFIRMED |
| F64 | `g_FreeDuelUnlocks` | Live-verified as a duelist unlock BITMASK: reads 0x40 (one bit) on this save, and the grid shows exactly one duelist (Simon Muran) + the Build Deck tile. The operator's full 8x5 board (through Duel Master K, with per-CPU WIN/LOSS) is the all-unlocked rendering. Mask may span >4 bytes for 39 duelists — extent unverified. | (name validated) | CONFIRMED |
| F65 | grid cursor scope | `g_GridCursorCol/Row` did NOT track cursor presses here — but with a 2-tile grid the navigation sample is too small; scope test deferred to a fuller roster. | (deferred) | HOLD |

### FREE DUEL grid cursor (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F66 | `0x8009B366/67` | The free-duel opponent-grid cursor: col byte +1 on RIGHT, row byte +1 on DOWN, both cleanly reversible. Sits in the duel-globals block right after `terrain`. The card-grid pair (g_GridCursorCol/Row) stays frozen here — each grid family has its own cursor block (F65 resolved). `opponentId` does NOT track hover — it must be set on selection. | `g_OpponentGridCol/Row` | APPLIED |
| F67 | `0x8009B36C/6D` | A second col/row pair moving in lockstep with the cursor — likely the previous-position pair used for un-highlighting. | prev pair (suspect) | HOLD |

### FREE DUEL refusal + deck commit proof (same session)

| # | address | what we proved | proposed name | status |
|---|---|---|---|---|
| F68 | duel-start guard | X on an opponent with an illegal deck: "YOUR DECK ISN'T READY!" banner, mode stays 0xC6 (modal), `opponentId` never set — the guard short-circuits before selection. The guard reads the COMMITTED deck (the build-deck working count is 0 outside that screen). | (fact) | CONFIRMED |
| F69 | F58 CLOSED — commit proven | `playerDeck` (save block) read back with the operator's 39-card edit: compacted, ascending, trailing zero. Deck edits COMMIT on build-deck exit (including the not-ready dialog's EXIT route). The staged-edit model is now complete: stage in working arrays -> commit compacted+sorted on exit. | (proof) | CONFIRMED |

## Structural notes (not names)

- The main-menu logic itself executes from a menu module loaded from disc
  into `0x80180000+` (call sites 0x80180924/0x801809C0/0x801809D0). It is
  OUTSIDE SLUS_014.11's static code — a third code space next to the main EXE
  and the duel overlay. Its data includes the cursor byte (0x80184594) and
  widget art/anim data around 0x801AF8xx.
- The recomp debug server's `press` command button mask: 0x10 moves the menu
  cursor DOWN, 0x40 UP (do not assume the standard PSX pad word).
- Menu-move widget pool objects live around 0x800F0698/0x800F0858 (0x1C0
  apart — likely an object array; pool base unknown yet).
- Menu-module dump captured live (tmp/menu_module_80180000.bin, 0x30000 span,
  ~24KB nonzero). The cursor handler's own store instructions located: sb to
  0x4594(base) at module PC 0x80180890 (one direction) and 0x801808C0 (the
  other), setter at 0x80180070; EXE call-outs at 0x80180924/9C0/9D0 follow.
  Handler body ~0x80180800-0x801809FF — first concrete disassembly anchor for
  the menu-module code space.
