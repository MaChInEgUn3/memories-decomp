#include "../types.h"

struct Arg0 {
    char pad0[4];
    s32 unk4;
    char pad8[4];
    s32 unkC;
    char pad10[4];
    s16 unk14;
};

/* PS1 scratchpad SPRT-primitive builder, reused for every sprite this
   function draws. */
struct Scratch {
    u32 f0;
    u16 f4;
    u16 f6;
    u32 f8;
    u16 fC;
    u8 fE;
    u8 fF;
    u16 f10;
    u16 f12;
    u32 f14;
};

extern void func_800849F0(void *sp, void *ot, s32 mode);

/* Tiles a 0xF0-tall x 0x140-wide checkerboard background out of 0x40x0x20
   sprite cells: two interleaved column passes per row (color/uv alternating
   between the 0x30/0x2C0 and 0x50/0x2D0 tile variants), sorted into `ot`
   with arg0's color/clut/tpage settings. */
void func_8003D334(struct Arg0 *arg0, void *ot) {
    struct Scratch *p = (struct Scratch *) 0x1F800000;
    s32 y;
    s32 flip;
    s32 mode;
    s32 x;
    s32 f4val;
    s32 fCval;

    f4val = arg0->unk4;
    p->f8 = 0x200020;
    p->f0 = f4val;
    fCval = arg0->unkC;
    p->fC = 0xB;
    p->f10 = 0x2C0;
    p->f12 = 0xFC;
    mode = arg0->unk14;
    *(u16 *) &p->fE = 0x3030;
    p->f14 = fCval;

    flip = 0;
    y = 0;
    do {
        x = 0;
        p->f4 = flip << 5;
        p->fE = 0x30;
        p->f6 = y;
        p->f10 = 0x2C0;
        do {
            func_800849F0(p, ot, mode & 0xFFFF);
            x += 0x40;
            p->f4 = p->f4 + 0x40;
        } while (x < 0x140);

        x = 0;
        p->f4 = (flip ^ 1) << 5;
        p->fE = 0x50;
        p->f10 = 0x2D0;
        do {
            func_800849F0(p, ot, mode & 0xFFFF);
            x += 0x40;
            p->f4 = p->f4 + 0x40;
        } while (x < 0x140);

        y += 0x20;
        flip ^= 1;
    } while (y < 0xF0);
}
