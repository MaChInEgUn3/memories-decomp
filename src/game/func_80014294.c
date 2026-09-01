#include "../types.h"

extern char D_8009B11C[1];
extern int D_8009B130, D_8009B0F4;
extern u16 D_8009B100;
extern void func_8007B1F4(int, void *, void *, int);

void func_80014294(u8 event)
{
    if (event == 5) {
        D_8009B130++;
        func_8007B1F4(0xD, D_8009B11C, func_80014294, -1);
    } else if (event == 2) {
        D_8009B100 = 4;
        D_8009B0F4 &= ~0x400;
    }
}
