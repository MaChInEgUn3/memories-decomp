typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 func_8003F70C(void);
extern void func_800356A0(void *, void *, s32);
extern void func_8003D0F4(void *);
extern u8 D_801D0200[], D_801D3200[];
s32 func_8003F810(void) {
    s32 r = func_8003F70C();
    if (r != 0) {
        if (r == 1) {
            u8 *p = D_801D0200;
            func_800356A0(p, D_801D3200, 0x680);
            func_8003D0F4(p);
        }
        return r;
    }
    return 0;
}
