# Symbols Guide

The confirmed symbols, organized by where in the game they actually run --
from matched code, live tracing of the running game, and confirmed community
knowledge. Markdown port of the shared Symbols Guide page; regenerate by hand
when the guide changes. Rosters: known_functions.md / known_variables.md.

## Everywhere — the engine

Runs on every screen. A live-computed core of 147 functions (GPU frame pump, SPU upkeep, pad, fades) beats under all of it; these are the named anchors.

| symbol | address | description |
|---|---|---|
| `mainLoop` | 0x8002DD74 | The master dispatch: never returns, runs the update funcs each frame, then calls the current mode's loop through a function-pointer table. |
| `gameInit` | 0x80012B50 | Boot-time setup before mainLoop takes over. |
| `vertBlankCallback` | 0x80012CD4 | Runs once per frame on the vertical blank. |
| `prngSeed` | 0x800FE6F8 | The random-number seed — shuffles, drops, and AI coin-flips all trace back here. |
| `setFilePosTable` | 0x800136E4 | Boot: resolves every file in fileNames to its disc position. |
| `fileNames` | 0x8009078C | Names of the data files on the disc. |
| `filePositions` | 0x800E9EA8 | Where each file lives on the CD. |
| `filePosition` | 0x800138F4 | Looks a file's position up. |
| `fileExists` | 0x8005C4F0 | Checks whether a file is present (wraps PsyQ DsSearchFile). |

### The sound driver (also everywhere)

| symbol | address | description |
|---|---|---|
| `SD_Init` | 0x800492D8 | Sound-system init. |
| `SD_Term` | 0x80049694 | Sound-system shutdown. |
| `SD_LoadData` | 0x80046768 | Loads sd_bgm.dat / sd_se.dat / master.xa from disc. |
| `SD_SEPlay` | 0x80048658 | Plays sound effect id at volume vol. Known ids: 6 cursor move, 7 confirm, 8 cancel, 0x2F option toggle. |
| `SD_SEPlayFull` | 0x8003FEE0 | Convenience wrapper: plays an effect at full volume — always SD_SEPlay(id, 0xFF). |
| `musicTrack` | 0x801EA800 | The current music track. (Below this, the SPU layer keeps original Sony PsyQ names.) |

## Main menu

NEW GAME / LOAD / 2P DUEL / TRADE / OPTION. The menu's own logic runs from a module loaded from disc into 0x80180000+ — the EXE supplies widgets, sound, and drawing.

| symbol | address | description |
|---|---|---|
| `mainMenuLoop` | 0x8002D588 | The main-menu mode tick. Dialogs (like TRADE's memory-card prompt) are modals inside it — the game never leaves this mode for them. |
| `g_MenuCursor` | 0x80184594 | The shared menu cursor: 0–4 on the main menu, 5–10 on the post-load menu (CAMPAIGN=5 … SAVE=10). Lives in the loaded menu module's data. |

## Options

| symbol | address | description |
|---|---|---|
| `optionsMenuLoop` | 0x8002D6C8 | The OPTION screen's mode tick. |
| `SD_SetOutputType` | 0x80046FA0 | The STEREO/MONO setter (0=stereo, 1=mono): writes the driver's mode byte and re-mixes CD audio on the spot. |
| `g_SoundMode` | 0x8009B408 | The stored stereo/mono setting. |

## Campaign overworld

| symbol | address | description |
|---|---|---|
| `campaignOverworldLoop` | 0x8002D2D8 | The campaign map's mode tick. |

## Build deck & trunk

Mode slot 7. Editing is STAGED: X-moves change working state only; the deck commits to the save block — compacted and sorted by card id — when you exit (any route). Leaving with fewer than 40 cards triggers the "YOUR DECK ISN'T READY!" modal, and every duel entrance re-checks the committed deck.

| symbol | address | description |
|---|---|---|
| `buildDeckMenuLoop` | 0x8002D370 | The deck-building screen's mode tick. |
| `working deck count` | 0x801D560C | The staged deck size (40 ↔ 39 during edits); guards read it inside the screen, and the committed deck elsewhere. |
| `playerDeck` | 0x801D0200 | Your 40-card deck (part of the save block). |
| `trunk` | 0x801D0250 | Your trunk — per-card counts of everything you own (part of the save block). |
| `compDeckCard` | 0x80032B60 | One of the two generic list comparators (with compare_rec_two_level_std): START cycles 7 sort orders, each mode rebuilds the records' sort keys and picks a comparator; trunk orders are computed once then cached, the deck re-sorts live. |
| `nameKeys` | 0x801D4D8E | Per-card sort keys for that comparison. |

## Card library

Mode slot 4. The card-detail page is a modal inside it; the full-size card art streams from the disc when the page opens.

| symbol | address | description |
|---|---|---|
| `libraryMenuLoop` | 0x8002D0E0 | The Library (card catalog) screen's mode tick. |
| `g_GridCursorCol / Row` | 0x8009B258 / 59 | The card grid's cursor position, one byte each (10-wide grid). The selected CARD is tracked by the global selectedCardId. |
| `setLibraryUsed` | 0x8002BF3C | Marks a card as seen in the catalog. |
| `toggleLibraryUsed` | 0x8002CCE4 | Flips that seen-flag. |

## Password screen

Mode slot 10 — a real mode switch. Passwords are one-time-use per save; a wrong or reused code is refused inside the screen's own module.

| symbol | address | description |
|---|---|---|
| `passwordMenuLoop` | 0x8002D684 | The password screen's mode tick (a name dispute settled by tracing). |
| `g_PasswordDigits` | 0x8016D410 | The 8 entry digits, one byte each, in the screen's own disc-loaded module. |
| `g_CardPasswords` | 0x801A8008 | The password + starchip-cost table the entry screen checks against — entering a password spends starchips from your save. |

## Your save file

The persistent block at 0x801D02xx–0x801D07xx — what actually goes to the memory card. These aren't tied to one screen: they're earned, spent, and edited all over the game.

| symbol | address | description |
|---|---|---|
| `playerDeck` | 0x801D0200 | Your 40-card deck — stored compacted and SORTED by card id, trailing zeros when short (commit-on-exit proven by byte diff). |
| `trunk` | 0x801D0250 | Per-card ownership counts (Build Deck, Library, drops all touch it). |
| `g_FreeDuelUnlocks` | 0x801D06F4 | Which duelists are unlocked in Free Duel (0xFFFFFFFF = all). |
| `g_LastCardDrops` | 0x801D07BC | The cards you most recently WON/acquired (drops and password buys both shift in; drives the trunk's New! tags and the NEW sort; capacity ~15-16 per the operator, extent unverified). |
| `starchips` | 0x801D07E0 | Your starchip balance — spent on password exchanges (deduction byte-verified live). |
| `used-password flags` | ~0x801D0698 | Set when a password is redeemed; re-entry then refuses ("already put in that password"). Bit layout still being mapped. |

## Free duel & name entry

Mode slot 6. An 8×5 opponent grid (Build Deck tile at top-left); the cursor roams every tile, but only duelists whose unlock bit is set are drawn. Selecting with an illegal deck is refused before opponentId is even written.

| symbol | address | description |
|---|---|---|
| `freeDuelMenuLoop` | 0x8002D3F8 | Free Duel opponent-select mode tick. |
| `g_OpponentGridCol / Row` | 0x8009B366 / 67 | The opponent grid's cursor, one byte per axis — its own block, separate from the card-grid cursor pair. |
| `nameEntryLoop` | 0x8002D62C | The name-entry screen's mode tick. |

## Duel — setup

| symbol | address | description |
|---|---|---|
| `shuffleDeck` | 0x800243F4 | Shuffles one deck (via the 40-byte permutation buffers). |
| `shuffleBothDecks` | 0x800245A0 | Shuffles yours and the computer's at duel start. |
| `playerPerm / cpuPerm` | 0x80177F94 / FBC | The two shuffle-permutation buffers. |
| `playerDeckTmp / cpuDeckTmp` | 0x80177FE8 / 0x80178038 | Shuffled working copies of each deck. |
| `cpuDeckPool` | 0x801781D8 | The card pool the computer's deck is drawn from. |

## Duel — in progress

| symbol | address | description |
|---|---|---|
| `playingSide` | 0x8009B1D5 | Whose side is acting. |
| `opponentId` | 0x8009B361 | Which duelist you're facing. |
| `terrain` | 0x8009B364 | The current field terrain. |
| `selectedCardId` | 0x8009B338 | The currently selected card — game-wide: it is also the Library grid's cursor (RIGHT +1, DOWN +10, proven live). |
| `g_PlayerHand` | 0x801A7E20 | Your hand (5 entries, 6 bytes each). |
| `activeCards` | 0x801AB000 | The cards in play on the field. |
| `playerMonsters` | 0x801A7B64 | Your five monster-zone slots. |
| `playerLp / playerDisplayedLp` | 0x800EA004 / 002 | Your life points — actual vs the on-screen ticking number. |
| `cpuLp / cpuDisplayedLp` | 0x800EA024 / 022 | The computer's, same split. |
| `g_FusionResult` | 0x800EA118 | Result of the last fusion attempt. |

## Duel — battle math

| symbol | address | description |
|---|---|---|
| `statsArray` | 0x801D4244 | Per-card packed stats records (ATK/DEF/type/guardian stars). |
| `baseCardStat` | 0x8002CBF4 | Base ATK or DEF ×10 from statsArray, plus terrain, clamped to 9999. |
| `gsBonus` | 0x8002CB80 | The Guardian Star wheel: two star ids → +500 / −500 / 0 (a 6-star cycle and a 4-star cycle). |
| `monGsBonus` | 0x8001EE44 | The same bonus evaluated for two monsters on the field. |
| `monBattleEffAtk / Def` | 0x8001EF1C / F78 | Effective ATK / DEF in battle, bonuses applied. |
| `getTerrainBoost` | 0x8002497C | The +/−500 field bonus by monster type on the current terrain. |
| `terrainBoosts` | 0x800909D4 | The table behind it. |
| `fusionTable` | 0x8017C2D8 | Every fusion combination in the game (u16 array). |
| `equipTable` | 0x8017A1D8 | Which equips work on which monsters. |
| `ritualData` | 0x801799D8 | The ritual recipes. |

## Duel — the computer opponent

> What the AI interpreter is: every duelist ships a bytecode script on the disc — their personality. When it's the computer's turn, the game loads that script into handAiScript and aiMain executes it instruction by instruction: test the board, branch, roll chances, and finally emit a move. The ~80 aiInst* functions are the instruction set of that little virtual machine. It runs only here — mid-duel, on the CPU's decision. Its cleverest pieces: aiInstFindBestA pits every AI monster against every opposing slot (ATK difference + guardian-star bonus) and leaves the best score/attacker/target in three slots the script reads back, and aiCompleteFusion recursively solves fusion chains from the AI's own hand.

| symbol | address | description |
|---|---|---|
| `aiMain` | 0x80070650 | The interpreter loop — dispatches each opcode via aiFunctionTable. |
| `aiFunctionTable` | 0x800916E0 | The opcode dispatch table (one entry per aiInst*). |
| `handAiScript` | 0x801A8000 | The loaded script being executed. |
| `aiStruct` | 0x800F5BE8 | The VM's state block (position, stack, flags). |
| `aiMemory` | 0x800F5B98 | The VM's scratch registers. |
| `aiStructInit` | 0x800705D8 | Resets the VM before a decision. |
| `aiHandSize` | 0x80070710 | The opponent's configured hand-size parameter from oppData. |
| `oppData` | 0x800917F0 | Per-duelist AI parameter records (9 bytes each). |
| `aiCompleteFusion` | 0x800727C0 | The computer working out a fusion chain from its own hand. |
| `aiInst* (~80 opcodes)` | 0x80070988+ | The instruction set: jumps (aiInstJumpEq/Rand/Mid…), call/return with a real stack, VM arithmetic, card/type sets, board scanners (aiInstStrongest/Weakest/FindCard…), the matchup search (aiInstFindBestA), and the move-emitters (aiInstFieldPlay, aiInstFaceUpPlay, the combo pushers). |

## Duel — battle animation

| symbol | address | description |
|---|---|---|
| `animatedBattleLoop` | 0x8002D180 | The 3D battle-animation mode tick (dispatches on the fusion recipe id). |

## End of duel — rank & rewards

| symbol | address | description |
|---|---|---|
| `calcRankScore` | 0x80021598 | Scores how you dueled — the number behind the S/A/B… POW/TEC grade. |
| `rankScoreChange` | 0x80021558 | Scores one statistic against the rankScoreDiffs thresholds. |
| `rankScore / rankScoreDiffs` | 0x80179A04 / 98A8 | The running score and the per-deed point table. |
| `cardDrop` | 0x80021810 | Rolls your reward card — a weighted draw (threshold 1–2048) over a 722-entry pool row. |
| `powDropPool / bcdDropPool / tecDropPool` | 0x8017878C… | The three drop tables, picked by your win style. |
| `g_CardDropId` | 0x80179A14 | The rolled drop (the last-10 history lives in the save block). |

## Game over & credits

| symbol | address | description |
|---|---|---|
| `gameOverLoop` | 0x8002D730 | The game-over screen's mode tick. |
| `creditsLoop` | 0x8002DA1C | The credits roll's mode tick. |
| `hirataLoop` | 0x8002D7C4 | Empty in retail — a compiled-out developer mode, named for the Konami programmer whose source path survives in the debug strings. |

## Debug leftovers

Development machinery that shipped in the retail binary.

| symbol | address | description |
|---|---|---|
| `g_DebugSoundId` | 0x8009B2C4 | Debug menu: last sound id played. |
| `FntOpen / FntPrint / FntFlush / SetDumpFnt` | 0x8007E9B0… | The PsyQ on-screen debug text channel — the game's printf-to-screen. |
| `aiInstPrint` | 0x800736C4 | An AI opcode that prints two debug strings (the "check_point" machinery) — AI scripts could narrate themselves during development. |
| `PCread` | 0x80073758 | Dev-kit leftover: file reads from the attached PC's filesystem (LIBSN); inert on retail hardware. |
