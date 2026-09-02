#include "../types.h"
#include "model.h"

void func_8005A468(s32 arg0, s32 arg1)
{
    ModelSlot *rec = &D_800F2C40[arg0];
    u8 **p;
    s32 i;

    p = (u8 **)rec->field_1E0;
    i = 0;
    if (rec->field_E1B != 0) {
        do {
            (*p)[0xD] = arg1;
            p++;
            i++;
        } while (i < rec->field_E1B);
    }
}
