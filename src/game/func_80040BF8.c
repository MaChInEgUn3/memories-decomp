typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef void (*ObjFn)(u8 *);
typedef struct Slot70 {
    s16 unk0;
    s16 unk2;
    u8 pad4[4];
    u16 flags;
    u16 unkA[13];
    ObjFn unk24;
    u8 pad28[0x70 - 0x28];
} Slot70;
extern s16 D_800EFE3E[];
extern Slot70 D_800EFE48[];
extern s32 D_800E9D90[];
extern void func_800408D0(u8 *, s32, s32);

void func_80040BF8(void) {
    s32 i = D_800EFE3E[0];

    if (i >= 0) {
        Slot70 *base = D_800EFE48;
        s32 *t = (s32 *)D_800E9D90;

        do {
            Slot70 *p = (Slot70 *)(i * 112 + (s32)base);
            ObjFn f = p->unk24;
            u8 *q = (u8 *)p;

            i = p->unk2;

            if (f != 0) {
                f(q);
            }

            if (((p->flags & 0xC0) ^ 0xC0) == 0) {
                func_800408D0(q, t[q[0x17]], *(s16 *)(q + 0x14));
            }
        } while (i >= 0);
    }
}
