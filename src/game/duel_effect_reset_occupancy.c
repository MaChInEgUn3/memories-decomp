#include "../types.h"

/* Clears the 240-byte D_800EAF08 occupancy table (see func_80035CA8 and
   find_free_slot_800eaf08) and resets its scan cursor to (0,0). */
extern u8 D_800EAF08[];
extern u8 D_8009B324;
extern u8 D_8009B325;

void DuelEffect_ResetOccupancy(void) {
    u8 *v0;
    int v1;
    v0 = D_800EAF08;
    v1 = 239;
    do {
        *v0 = 0;
        v1 = v1 - 1;
        v0 = v0 + 1;
    } while (v1 >= 0);
    D_8009B324 = 0;
    D_8009B325 = 0;
}
