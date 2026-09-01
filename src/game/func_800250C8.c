#include "../types.h"

/* Advances the duel-field "camera nudge" object (D_8009B1C8) by a per-turn
   step read from the D_8009AF30 lookup table, or spawns a placeholder object
   (via func_8002C68C) the first time flag80 hasn't been claimed yet this
   frame. D_8009B220 bit 0x40 alternates which of the two advance directions
   (push/pull) runs; bit 0x20 gates a one-shot "settle" object spawn once
   duel_flags_state_and_field_spawn_dispatch reports the motion finished. */

struct Obj {
    s16 field0;
    s16 field2;
    u8 pad[0x1A - 4];
    s16 field1A;
};

struct SomeState2 {
    u8 pad[0x14];
    u16 unk14;
    s16 unk16;
};

extern s16 D_8009B1D2;
extern struct SomeState2 *D_8009B1C8;
extern u16 D_8009B220;
extern u16 D_8009B210;
extern s16 D_8009B22A;
extern u8 D_8009AF30[4];

s32 func_80024E24(void);
s32 func_8001F364(s32);
s32 func_80025028(s32);
struct Obj *func_8002C68C(s32);
void SD_SEPlayFull(u32);

void func_800250C8(void) {
    s32 s0;
    s32 s1;
    s32 flag;
    u16 v1;
    struct Obj *obj;

    s0 = D_8009B1D2;
    s1 = s0 - 0x152;
    if (func_80024E24() == 0) {
        if (func_80025028(0x2B0) != 0) {
            s1 = s0 - 0x14D;
        }
        obj = func_8002C68C(5);
        obj->field0 = 0xA0;
        obj->field2 = 0x78;
        obj->field1A = s1;
        SD_SEPlayFull(0x14);
        return;
    }
    flag = D_8009B220;
    if (!(flag & 0x40)) {
        D_8009B220 = flag | 0x60;
        if (D_8009B22A == 0) {
            u8 *p = &D_8009AF30[s1];
            v1 = D_8009B1C8->unk14 + (*p) * 0x64;
            D_8009B1C8->unk14 = v1;
            if (D_8009B1C8->unk16 < (s16) v1) {
                D_8009B1C8->unk14 = (u16) D_8009B1C8->unk16;
            }
            goto block_14;
        }
        D_8009B210 = 0;
        goto block_9;
    }
block_9:
    if (D_8009B220 & 0x20) {
        if (func_8001F364(flag) == 0) {
            D_8009B220 &= 0xFFDF;
            obj = func_8002C68C(9);
            obj->field0 = 0xA0;
            obj->field2 = 0x78;
            obj->field1A = s1;
        }
    } else {
        u8 *p = &D_8009AF30[s1];
        v1 = D_8009B1C8->unk14 - (*p) * 0x64;
        D_8009B1C8->unk14 = v1;
        if ((s16) v1 < 0) {
            D_8009B1C8->unk14 = 0;
        }
block_14:
        D_8009B220 = 0;
    }
}
