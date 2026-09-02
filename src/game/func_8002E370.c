#include "../types.h"

/* 3-entry table (stride 0x4C); s8 at offset 0x30 is a signed marker byte. */
struct Entry {
    u8 pad[0x30];
    s8 flag30;
    u8 pad2[0x4C - 0x31];
};

struct Obj {
    u8 pad[0x34];
    u16 flags;
};

extern struct Entry D_800EB010[3];

/* Walks D_800EB010 backward from index 2 to 0; on the first entry whose
   flag30 is non-negative, sets bit 0x2 in a0->flags and returns. Does
   nothing if all three entries have flag30 < 0. */
void func_8002E370(struct Obj *a0) {
    int count;
    struct Entry *p;
    int v0;

    count = 2;
    p = &D_800EB010[count];
    do {
        v0 = p->flag30;
        count -= 1;
        if (v0 >= 0) {
            a0->flags |= 2;
            return;
        }
        p -= 1;
    } while (count >= 0);
}
