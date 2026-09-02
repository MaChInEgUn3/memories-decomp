#include "../types.h"

/* Stride-28 entry, field17/field18 relative to a base 17 bytes into
   D_800EB288. */
struct Entry {
    u8 field17;
    u8 field18;
    u8 pad[28 - 2];
};

extern u8 D_800EB288[];

/* Clears field17 on the first (only) entry whose field18 equals a0+1,
   scanning 620 entries. */
void func_80035DB8(int a0) {
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
