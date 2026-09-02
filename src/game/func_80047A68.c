#include "../types.h"
#include "sound.h"

extern void func_80076ED0(s32, u32);

void func_80047A68(void)
{
    s32 i;
    u32 mask = 0x100000;
    u32 result = 0;
    u16 threshold = g_SDValue->field_0004;

    for (i = 0; i < 4; i++) {
        if (g_SDValue->voice_ids[i] >= threshold) {
            result |= mask;
        }
        mask <<= 1;
    }
    func_80076ED0(0, result);
}
