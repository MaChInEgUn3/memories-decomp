#include "../types.h"
#include "sound.h"

extern int func_800496C4(void *, int, int);

void func_80049308(void)
{
    SDValue *state = g_SDValue;
    if (state->field_157A != 0) {
        u8 *entry = (u8 *)state->music_track;
        int result = func_800496C4(entry + 0x50, 0, *(int *)(entry + 0x0C));
        g_SDValue->field_157A = result;
        if ((result << 16) != 0) {
            g_SDValue->field_1578 = -1;
            g_SDValue->field_157A = -1;
            return;
        }
    }
    {
        register SDValue *final = g_SDValue;
        register u16 *entry = final->music_track;
        final->field_1578 = *entry;
    }
}
