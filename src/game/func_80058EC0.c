#include "../types.h"
#include "model.h"

u16 func_80058EC0(s32 idx) {
    u8 sub = D_800F2C40[idx].field_BF5;
    {
        u8 *base = (u8 *)D_800F2C40;
        return *(u16 *)(idx * 0xE20 + sub * 118 + base + 0x7C4);
    }
}
