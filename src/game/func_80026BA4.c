#include "../types.h"

extern u16 D_8009B1A8, D_8009B1D2, D_8009B220;

void func_80026BA4(int value, int flag)
{
    int index;
    if (((unsigned)(value - 0x12D) < 50) ||
        ((unsigned)(value - 0x28B) < 50) || value == 0x2D1) {
        if (value < 0x28B) index = value - 0x12D;
        else {
            index = value - 0x259;
            if (value == 0x2D1) index = 100;
        }
        D_8009B1A8 = index;
        D_8009B1D2 = value;
        D_8009B220 = 0x8000;
        if (flag) D_8009B220 = 0xC000;
    }
}
