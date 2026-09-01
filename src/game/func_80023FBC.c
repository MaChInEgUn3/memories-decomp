typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Same 2-element history slot as reset_history_ring_and_flags.c's
   D_8009B3A4[2]; only index 0 is read here (declared scalar -- an array
   extern forces absolute lui/addiu addressing here instead of the target's
   gp-relative access). */
extern volatile u16 D_8009B3A4;

struct Obj {
    u8 pad[25];
    u8 field25;
};

extern void func_80023D08(struct Obj *a0, s32 a1);

/* Priority-encodes D_8009B3A4's status bits into a small index (-1 if
   none of 0x1000/0x2000/0x4000/0x8000 are set; otherwise whichever of
   those bits, checked in 0x2000/0x4000/0x8000/0x1000 order, was seen last
   wins), then forwards a0 through to func_80023D08 with that index as the
   second argument. Reloads the volatile global on every check rather than
   caching it in a register, matching the ROM's real per-check reload. */
void func_80023FBC(struct Obj *a0) {
    s32 a1 = -1;

    if (D_8009B3A4 & 0xF000) {
        if (D_8009B3A4 & 0x2000) {
            a1 = 0;
        }
        if (D_8009B3A4 & 0x4000) {
            a1 = 1;
        }
        if (D_8009B3A4 & 0x8000) {
            a1 = 2;
        }
        if (D_8009B3A4 & 0x1000) {
            a1 = 3;
        }
    }

    func_80023D08(a0, a1);
}
