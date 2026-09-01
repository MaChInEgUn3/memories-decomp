#include "../types.h"

extern u16 D_8009B3A6, D_8009B39A, D_8009B396;
extern u8 D_800EF6B0[];
extern u32 D_8009B390, D_8009B3B0, D_8009B3B4, D_8009B3A8;
void func_8003CB7C(void) {
    s32 i = 1;
    volatile u16 *c = &D_8009B3A6;
    volatile u16 *b = &D_8009B39A;
    volatile u16 *a = &D_8009B396;
    u8 *base;
    do {
        *a = 0;
        *b = *a;
        *c = *b;
        a--; b--; c--; i--;
    } while (i >= 0);
    i = 0x1F;
    base = D_800EF6B0;
    for (; i >= 0; i--) {
        *(u8 *)((u32)i + (u32)base) = 0;
    }
    D_8009B390 = 0;
    D_8009B3B0 = 0;
    D_8009B3B4 = 0;
    D_8009B3A8 = 0;
}
