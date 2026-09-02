#include "../types.h"

#include "fade.h"

extern u8 D_8009B145;
extern void func_80015780(void);
extern void func_8001572C(void);

void func_8001581C(int arg0)
{
    FadeTransitionState *state;

    if (arg0 == 0xFFFFFF) {
        D_8009B145 = 1;
    }
    *(s32 *)&D_800E9EC8 = arg0;
    func_80015780();
    state = &D_800E9EC8;
    state->flags |= 0x30;
    func_8001572C();
}
