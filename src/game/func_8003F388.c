typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern u8 D_800EB0F8[];
extern u8 D_8009B3EE;
extern u8 *D_8009B3D8;
extern u8 *func_8004002C(void);
extern u8 *func_800400AC(u8 *, s32);
extern void func_800404CC(u8 *, s32, s32, s32, s32, s32, s32, s32);
extern void func_80042918(u8 *);
extern void func_800428EC(u8 *, s32);

void func_8003F388(void) {
    s32 i = 0;
    u8 *p = (u8 *)D_800EB0F8;
    u8 *o;

    D_8009B3EE = 0;

    for (; i < 4; i++) {
        if (!(*(u16 *)(p + 0x34) & 0x8000)) {
            D_8009B3EE = i;

            break;
        }
        p += 0x64;
    }

    o = func_800400AC(func_8004002C(), 2);
    func_800404CC(o, 0x20, -0x40, 3, 2, 1, 0xB, 0x20C);
    *(u16 *)(o + 8) |= 0x28;
    func_80042918(o);
    func_800428EC(o, 0xF);
    D_8009B3D8 = o;
}
