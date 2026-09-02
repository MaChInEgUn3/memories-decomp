#include "../types.h"
#include "sound.h"

extern void func_80076ED0(int, int);

int func_80047F38(u8 value)
{
    int i;
    int result = 0;
    int mask = 1;
    SDValue *state = g_SDValue;
    for (i = 0; i < 4; i++, mask <<= 1) {
        if ((state->voice_flags[i] & 0xF) == value)
            result |= mask;
    }
    if (result != 0)
        func_80076ED0(0, result << 20);
    return result;
}
