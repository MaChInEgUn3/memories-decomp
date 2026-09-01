#include "../types.h"

typedef struct {
    u8 pad[0x1E0];
    void *ptrs[1];
    u8 pad2[0xBF5 - 0x1E0 - 4];
    u8 field_bf5;
    u8 pad3[0xDCE - 0xBF5 - 1];
    u16 field_dce;
    u8 pad4[0xE06 - 0xDCE - 2];
    u16 field_e06;
    u8 pad5[0xE1B - 0xE06 - 2];
    u8 field_e1b;
    u8 pad6[0xE20 - 0xE1B - 1];
} RecD800F2C40;
extern RecD800F2C40 D_800F2C40[];
extern s32 func_8004DC38(void *, s32, s32, s32);

void func_800597C8(s32 idx, s32 flag, s32 val) {
    s32 i = 0;
    RecD800F2C40 *rec = &D_800F2C40[idx];
    s32 count;
    s32 arg3;

    count = rec->field_e1b;
    rec->field_e06 = val << 4;
    arg3 = rec->field_e06;

    if (count != 0) {

        do {
            s32 arg2 = rec->field_bf5;

            if (flag != 0) {
                u8 *entry = rec->ptrs[i];
                arg2 = flag;
                entry[0xC] = flag;
            }

            func_8004DC38(rec, i, arg2, arg3);
            count = rec->field_e1b;
            i++;
        } while (i < count);
    }

    if (flag != 0) {
        rec->field_bf5 = flag;
    }
    rec->field_dce = 0;
}
