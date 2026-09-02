#include "../types.h"

#include "fade.h"

extern void func_800158B8(void);
extern void func_80015870(void);

void func_80015904(void)
{
    FadeTransitionState *state;

    func_800158B8();
    state = &D_800E9EC8;
    state->step = 8;
    state->flags |= 1;
    func_80015870();
}
