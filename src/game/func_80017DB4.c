#include "../types.h"

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

struct Table801A7AD8 {
    char pad0[4];
    struct Inner *f4;
    char pad1[0x14 - 8];
    s32 f14;
    char pad2[0x1C - 0x18];
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

extern struct Table801A7AD8 D_801A7AD8[];
extern struct SomeState *D_8009B1C8;

void func_80017DB4(struct Obj *a0) {
    struct Table801A7AD8 *a1 = &D_801A7AD8[a0->f6A];

    if ((a1->f14 & 0xA0000000) != 0xA0000000) {
        return;
    }
    if (D_8009B1C8->f1F != 0) {
        a0->f67 = a1->f4->f4 + 1;
    }
    if (D_8009B1C8->f1F < 0) {
        a0->f67 = 0xFF;
    }
}
