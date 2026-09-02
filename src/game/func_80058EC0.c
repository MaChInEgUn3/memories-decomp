#include "../types.h"
#include "model.h"

u16 func_80058EC0(s32 idx) {
    u8 sub = D_800F2C40[idx].field_BF5;
    return D_800F2C40[idx].field_7C4[sub].field_00;
}
