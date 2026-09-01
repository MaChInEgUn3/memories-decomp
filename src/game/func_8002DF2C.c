#include "../types.h"

extern void func_8002DDFC(void);
extern unsigned char *func_80014EEC(int, int, int, int, void *, int, int);
extern unsigned int D_8009B0F4;

void func_8002DF2C(volatile unsigned char *owner, int value)
{
    int index;
    int mode;
    int stride;
    int base;
    unsigned char *object;

    if (owner) {
        *(short *)(owner + 0x3C) = value;
    }

    index = ((value >> 4) & 15) * 10 + (value & 15);
    mode = value >> 8;
    switch (mode) {
    case 0:
        stride = 0x21;
        base = 0;
        break;
    case 1:
        stride = 0x51;
        base = 0x672;
        break;
    case 2:
        stride = 0x71;
        base = 0x13BC;
        break;
    default:
        return;
    }
    object = func_80014EEC(
        0, 0, base + index * stride + 0x21D5, stride,
        func_8002DDFC, 0, 0
    );
    *(int *)(object + 0x38) = stride - 1;
    D_8009B0F4 = *(unsigned int *)(object + 0x2C) | 0x10;
}
