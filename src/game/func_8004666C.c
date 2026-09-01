#include "../types.h"

extern u8 * volatile g_SDValue;

void func_8004666C(void)
{
    u8 *first = g_SDValue;
    u8 *state;
    first[0x49] = 255;
    state = g_SDValue;
    *(short *)(first + 0x512) = 64;
    *(u16 *)(state + 0x40) = (*(u16 *)(state + 0x40) & 0xFFFC) | 4;
    if ((*(u16 *)(state + 0x40) & 0x80) &&
        *(short *)(state + 0x1588) >= 0) {
        *(short *)(state + 0x1588) = -16;
        state[0x1584] = 220;
    }
}
