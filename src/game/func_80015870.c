#include "../types.h"

#include "fade.h"

extern u8 D_8009B145;
extern u8 D_8009B14A;
extern u8 D_8009B14B;
extern u8 D_8009B14C;

void func_80015870(void)
{
    FadeTransitionState *state;
    int value;
    if (D_8009B145 != 0) {
        value = 0xFFFFFF;
        state = &D_800E9EC8;
        *(s32 *)state = value;
        state->flags = 0xB0;
        state->step = 0xC;
        D_8009B14A = 0xFF;
        D_8009B14B = 0xFF;
        D_8009B14C = 0xFF;
    }
}
