#include "../types.h"

extern u8 *g_SDValue;
extern void func_800495DC(void);
extern void func_800495EC(void);
extern void func_80044DC0(int);

void SD_SetOutputType(short value)
{
    u8 *state = g_SDValue;
    if (state[0x48] != value) {
        state[0x48] = value;
        if (value == 0)
            func_800495DC();
        else
            func_800495EC();
        func_80044DC0(*(short *)(g_SDValue + 0x510));
    }
}
