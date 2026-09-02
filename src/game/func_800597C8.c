#include "../types.h"
#include "model.h"
extern s32 func_8004DC38(void *, s32, s32, s32);

void func_800597C8(s32 idx, s32 flag, s32 val) {
    s32 i = 0;
    ModelSlot *rec = &D_800F2C40[idx];
    s32 count;
    s32 arg3;

    count = rec->field_E1B;
    rec->field_E06 = val << 4;
    arg3 = rec->field_E06;

    if (count != 0) {

        do {
            s32 arg2 = rec->field_BF5;

            if (flag != 0) {
                u8 *entry = rec->field_1E0[i];
                arg2 = flag;
                entry[0xC] = flag;
            }

            func_8004DC38(rec, i, arg2, arg3);
            count = rec->field_E1B;
            i++;
        } while (i < count);
    }

    if (flag != 0) {
        rec->field_BF5 = flag;
    }
    rec->field_DC8[3] = 0;
}
