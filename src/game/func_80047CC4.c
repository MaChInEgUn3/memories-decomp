#include "../types.h"
#include "sound.h"

extern int func_80047C50(int);
extern void func_80047C70(int);

void func_80047CC4(int value)
{
    int normalized = func_80047C50((u16)value);
    SDValue *state = g_SDValue;
    int tries = 0;
    int slot = state->field_0435;
    int bit = 1 << (u8)slot;
    int command = 1 << ((u8)slot + 20);
    do {
        state = g_SDValue;
        if (state->voice_active_mask & bit) {
            if (state->voice_ids[(u8)slot] == (u16)normalized) {
                func_80047C70(command);
                g_SDValue->field_0435 = slot;
                g_SDValue->voice_active_mask &= ~bit;
                break;
            }
        }
        bit <<= 1;
        command <<= 1;
        if (bit & 0x10)
            bit = 1;
        slot++;
        tries++;
        slot &= 3;
    } while (tries < 4);
}
