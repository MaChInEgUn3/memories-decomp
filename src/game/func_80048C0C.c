#include "../types.h"
#include "sound.h"

void func_80048C0C(u16 value, u8 enabled)
{
    int i;
    int mask;
    if (enabled == 0)
        return;
    mask = 1;
    for (i = 0; i < 4; i++, mask <<= 1) {
        SDValue *state = g_SDValue;
        if (state->voice_ids[i] == value &&
            (state->voice_active_mask & mask)) {
            state->voice_step[i] = enabled;
        }
    }
}
