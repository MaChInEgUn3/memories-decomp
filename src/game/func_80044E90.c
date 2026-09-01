#include "../types.h"

extern u8 *g_SDValue;
extern void func_80044DC0(int);

void func_80044E90(int value)
{
    register int saved asm("$5") = value;
    if ((u16)(value - 1) < 128) {
        g_SDValue[0x514] = -128 - saved;
        g_SDValue[0x515] = 128;
    } else if ((u16)(value + 128) < 128) {
        g_SDValue[0x514] = 128;
        g_SDValue[0x515] = -128 - saved;
    } else {
        g_SDValue[0x514] = 128;
        g_SDValue[0x515] = 128;
    }
    func_80044DC0(*(short *)(g_SDValue + 0x510));
}
