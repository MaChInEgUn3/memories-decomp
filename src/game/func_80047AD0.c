#include "../types.h"
#include "sound.h"

extern void func_80047A68(void);
extern void func_8004763C(void);
extern void func_80047788(u16);

int func_80047AD0(int value)
{
    u16 index = value;
    SDValue *state = g_SDValue;

    if (state->field_0448[index].field_0004 == 0)
        return 1;
    if (state->field_0442 == index)
        return 1;
    func_80047A68();
    func_8004763C();
    {
        register SDValue *final = g_SDValue;
        register int call_value = index;
        final->field_0442 = value;
        final->flags_0040 |= 2;
        func_80047788(call_value);
    }
    return 1;
}
