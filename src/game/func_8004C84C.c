#include "../types.h"

/* Same *D_8009B458 struct as set_8009b458_510_validated.c (f510 = item
   count, 1..20). Walks the 0x28-byte item array starting at offset 0x180
   and, for each item whose durability (f1E) is non-zero and whose type
   byte (f3) is below 0x10, decrements the durability by 1; otherwise
   resets it to 0. */
struct Item {
    char pad[3];
    u8 f3;
    char pad2[0x1E - 4];
    u16 f1E;
    char pad3[0x28 - 0x20];
};

struct S8009B458 {
    char pad0[0x180];
    struct Item items[20];
    char pad1[0x510 - (0x180 + 20 * 0x28)];
    s16 f510;
};

extern struct S8009B458 *D_8009B458;

void func_8004C84C(void) {
    s32 i;

    for (i = 0; i < D_8009B458->f510; i++) {
        struct Item *item = &D_8009B458->items[i];
        if (item->f1E != 0 && item->f3 < 0x10) {
            item->f1E -= 1;
        } else {
            item->f1E = 0;
        }
    }
}
