#include "../types.h"

#include "fade.h"

extern u8 D_8009B145;
extern void func_800158B8(void);
extern void func_80015870(void);

void func_80015944(int arg0)
{
    FadeTransitionState *state;

    if (arg0 == 0xFFFFFF) {
        D_8009B145 = 1;
    }
    *(s32 *)&D_800E9EC8 = arg0;
    func_800158B8();
    state = &D_800E9EC8;
    state->flags |= 0x30;
    func_80015870();
}
