#include "../types.h"

#include "fade.h"

extern void func_80012D4C(void);

void func_80015998(void)
{
    FadeTransitionState *state = &D_800E9EC8;

    do {
        func_80012D4C();
    } while (state->flags & 0x80);
}
