#include "../types.h"

extern unsigned char D_8009B2EA, D_8009B2B4, D_8009B2B5, D_8009B2B6;
extern unsigned char D_8009B2E9, D_8009B2DC, D_8009B2B8, D_8009B2C2;
extern unsigned char D_8009B2C1, D_8009B2C0, D_8009B2E0;
extern void *D_8009B2EC;
void func_80030250(void *a, int b, int c, int d, int e, int f, int g) {
    D_8009B2EA = 0; D_8009B2EC = a;
    D_8009B2B4 = b; D_8009B2B5 = c; D_8009B2B6 = d;
    D_8009B2E9 = 0; D_8009B2DC = 0; D_8009B2B8 = e;
    D_8009B2C2 = f; D_8009B2C1 = f; D_8009B2C0 = f; D_8009B2E0 = g;
}
