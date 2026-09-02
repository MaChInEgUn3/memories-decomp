#include "../types.h"
#include "sound.h"

extern void func_8004A2F8(void);
extern s32 func_8004CABC(void);

void func_80049EC8(s32 arg0, s32 arg1)
{
    SDSecondaryState *state = D_8009B458;
    s32 mode = state->field_07E2;

    state->field_07E4 = arg0 & 0x7F;
    state->field_07E6 = arg1 & 0x7F;
    if (mode != 2)
        func_8004A2F8();
}

void func_80049F10(s16 first, s16 second)
{
    SDSecondaryState *state = D_8009B458;

    state->field_0514 = first;
    state->field_0516 = second;
    if (state->field_07E2 != 2)
        func_8004A2F8();
}

s32 func_80049F50(void)
{
    s32 value;

    if (D_8009B458->field_07E2 == 1) {
        value = (s16)func_8004CABC();
        if (value == 3)
            D_8009B458->field_07E2 = value;
    }
    return D_8009B458->field_07E2;
}
