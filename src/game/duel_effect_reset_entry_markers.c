#include "../types.h"

/* Same stride-28 table as DuelEffect_ClearMatchingMarker/reset_free_slot pairing (see
   clear_matching_byte_800eb288.c): clears field17 and the byte at
   struct-relative offset 7 on all 620 entries. */
extern u8 D_800EB288[];

void DuelEffect_ResetEntryMarkers(void) {
    u8 *v0;
    int v1;
    int off;
    v1 = 620;
    off = 24;
    v0 = D_800EB288;
    v0 = v0 + off;
    for (; v1 != 0; v1 = v1 - 1) {
        v0[-7] = 0;
        v0[0] = 0;
        v0 = v0 + 28;
    }
}
