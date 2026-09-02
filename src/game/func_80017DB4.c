#include "../types.h"
#include "duel_card.h"

/* Same D_801A7AD8[] stat table (0x1C-byte stride) as func_8001EFD4.c, and
   the same D_8009B1C8->f1F check as create_obj_set_flag_and_marker.c. If
   the record at D_801A7AD8[a0->f6A] has all of flags bits 0xA0000000 set,
   and D_8009B1C8->f1F is nonzero, sets a0->f67 from the record's nested
   f4->f4 byte (+1); if f1F reads negative by the second check, overwrites
   f67 with 0xFF instead. */
struct Inner {
    char pad[4];
    u8 f4;
};

struct SomeState {
    char pad[0x1F];
    s8 f1F;
};

struct Obj {
    char pad[0x67];
    u8 f67;
    char pad2[0x6A - 0x68];
    u8 f6A;
};

extern struct SomeState *D_8009B1C8;

void func_80017DB4(struct Obj *a0) {
    DuelCardRecord *a1 = &D_801A7AD8[a0->f6A];

    if ((*(s32 *)&a1->terrain_modifier & 0xA0000000) != 0xA0000000) {
        return;
    }
    if (D_8009B1C8->f1F != 0) {
        a0->f67 = ((struct Inner *)a1->data)->f4 + 1;
    }
    if (D_8009B1C8->f1F < 0) {
        a0->f67 = 0xFF;
    }
}
