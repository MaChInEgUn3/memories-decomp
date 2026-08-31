typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern u8 D_800F2848[];
extern s32 func_80086770(s32);
extern s32 func_800866A0(s32);
extern void func_800134E0(u8 *, s32, s32, s32);

void func_8001352C(void) {
    u8 *p = D_800F2848;
    s32 n = -*(s16 *)D_800F2848;
    s32 x = n * func_80086770(*(s16 *)(p + 4)) / 4096;
    s32 z = n * func_800866A0(*(s16 *)(p + 4)) / 4096;
    s32 y = x * func_800866A0(*(s16 *)(p + 2)) / 4096;
    s32 w = x * func_80086770(*(s16 *)(p + 2)) / 4096;

    x = w;
    func_800134E0(p, x, z, y);
}
