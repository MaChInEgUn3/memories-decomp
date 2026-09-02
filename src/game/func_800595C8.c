#include "../types.h"
#include "model.h"

void func_800595C8(s32 index, s32 x, s32 y, s32 z)
{
    u8 *record = (u8 *)&D_800F2C40[index];

    x = x < -4096 ? -4096 : (x > 12288 ? 12288 : x);
    *(s32 *)(record + 3488) = x;
    y = y < -4096 ? -4096 : (y > 12288 ? 12288 : y);
    *(s32 *)(record + 3492) = y;
    z = z < -4096 ? -4096 : (z > 12288 ? 12288 : z);
    *(s32 *)(record + 3496) = z;
    if (record[3601] != 4) {
        if (x == 2048 && y == x && z == y)
            record[3601] = 0;
        else
            record[3601] = 3;
    }
}
