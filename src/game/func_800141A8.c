#include "../types.h"

extern int D_8009B130, D_8009B0F4;
extern u8 D_800E9EA7[9];
extern void func_8007B1F4(int, void *, void *, int);

void func_800141A8(u8 event)
{
    if (event == 5) {
        D_8009B130++;
        func_8007B1F4(9, 0, func_800141A8, -1);
    } else if (event == 2) {
        D_800E9EA7[0] = 1;
        D_8009B0F4 &= ~0x400;
    }
}
