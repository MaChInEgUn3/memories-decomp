#include "../types.h"

#include "fade.h"

void func_80015BF0(int value)
{
    FadeTransitionState *state = &D_800E9EC8;

    state->level = value;
    state->target_level = value;
    state->flags = 0x80;
}
