#include "../types.h"
#include "sound.h"

extern void func_80047788(u16);

int func_80047B68(u16 value)
{
    SDValue *state = g_SDValue;
    if (state->field_0442 == value)
        return 1;
    state->field_0442 = value;
    state->flags_0040 |= 2;
    func_80047788(value);
    return 1;
}
