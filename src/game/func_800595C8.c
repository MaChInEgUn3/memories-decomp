#include "../types.h"
#include "model.h"

void func_800595C8(s32 index, s32 x, s32 y, s32 z)
{
    ModelSlot *record = &D_800F2C40[index];

    x = x < -4096 ? -4096 : (x > 12288 ? 12288 : x);
    record->field_DA0[0] = x;
    y = y < -4096 ? -4096 : (y > 12288 ? 12288 : y);
    record->field_DA0[1] = y;
    z = z < -4096 ? -4096 : (z > 12288 ? 12288 : z);
    record->field_DA0[2] = z;
    if (record->field_E11 != 4) {
        if (x == 2048 && y == x && z == y)
            record->field_E11 = 0;
        else
            record->field_E11 = 3;
    }
}
