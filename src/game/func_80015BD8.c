#include "../types.h"

#include "fade.h"

void func_80015BD8(int value, int flags)
{
    FadeTransitionState *state = &D_800E9EC8;

    state->target_level = value;
    state->flags = flags | 0x80;
}
