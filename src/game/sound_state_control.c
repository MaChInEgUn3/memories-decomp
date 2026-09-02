#include "../types.h"
#define SDSECONDARYSTATE_CUSTOM_EXTERN
#include "sound.h"

extern SDSecondaryState *volatile D_8009B458;

void func_8004695C(s32 value)
{
    u8 *state;

    D_8009B458->field_0509 = value;
    state = (u8 *)D_8009B458;
    if (state[0x509] != 0)
        state[0x500] = 1;
    else
        state[0x500] = 0;
}

void func_80046990(s32 first, s32 second, s32 third)
{
    g_SDValue->field_003C = 0;
    if (first == 0)
        g_SDValue->flags_004A &= 0xFE;
    if (second == 0)
        g_SDValue->flags_004A &= 0xFD;
    if (third == 0)
        g_SDValue->flags_004A &= 0xBF;
    g_SDValue->flags_0040 |= 0xA;
}
