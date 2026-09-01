#include "../types.h"

extern u32 D_800E9DB0[];
extern u32 D_8009B0B8;

/* Zeroes D_800E9DB0[0..3] and D_8009B0B8. */
void func_800134B4(void) {
    u32 *v0;
    int v1;
    v1 = 3;
    v0 = &D_800E9DB0[v1];
    do {
        *v0 = 0;
        v1 -= 1;
        v0 -= 1;
    } while (v1 >= 0);
    D_8009B0B8 = 0;
}
