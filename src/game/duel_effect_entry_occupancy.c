#include "../types.h"

extern u8 D_800EAF08[];
extern u8 D_8009B324;
extern u8 D_8009B325;
extern u8 D_800EB288[];

/* Stride-28 entry, field17/field18 relative to a base 17 bytes into
   D_800EB288. */
struct Entry {
    u8 field17;
    u8 field18;
    u8 pad[28 - 2];
};

void func_80035CA8(int value)
{
    int index;
    u8 *entry = D_800EAF08;
    value++;
    for (index = 0; index < 0xF0; index++, entry++) {
        if (*entry == value) {
            *entry = 0;
        }
    }
}

/* Clears the 240-byte D_800EAF08 occupancy table (see func_80035CA8) and
   resets its scan cursor to (0,0). */
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

s32 func_80035D10(void)
{
    s32 col = D_8009B324;
    s32 row = D_8009B325;
    s32 count = 0x100;
    do {
        s32 index = row * 16 + col;
        if (D_800EAF08[index] == 0)
            return index;
        col++;
        if ((col & 3) == 0) {
            row++;
            if (row >= 0xF)
                row = 0x10;
            if ((row & 3) == 0)
                row -= 4;
            else
                col -= 4;
            if (col >= 0x10) {
                row += 4;
                col = 0;
                if (row >= 0x10)
                    row = 0;
            }
        }
        count--;
    } while (count != 0);
    return -1;
}

/* Clears field17 on the first (only) entry whose field18 equals a0+1,
   scanning 620 entries. */
void DuelEffect_ClearMatchingMarker(int a0) {
    struct Entry *v1;
    int a1;
    u8 v0;
    int off;
    a1 = 620;
    a0 = a0 + 1;
    off = 17;
    v1 = (struct Entry *)(D_800EB288 + off);
    do {
        v0 = v1->field18;
        if (v0 == a0) {
            v1->field17 = 0;
        }
        a1 -= 1;
        v1 += 1;
    } while (a1 != 0);
}

/* Clears field17 and the byte at struct-relative offset 7 on all 620
   stride-28 entries. */
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
