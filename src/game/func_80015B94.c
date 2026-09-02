#include "../types.h"

#include "fade.h"

extern void func_800158B8(void);
extern void func_80015870(void);
extern void func_80015998(void);

void func_80015B94(void)
{
    FadeTransitionState *state;

    func_800158B8();
    state = &D_800E9EC8;
    state->flags |= 6;
    func_80015870();
    func_80015998();
}
