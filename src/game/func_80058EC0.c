#include "../types.h"

/* Same D_800F2C40 record table as get_D_800F2C40_slot_field_bf5.c. Reads the
   byte field at 0xBF5 and uses it as a sub-index into a 118-byte-stride
   array of u16 entries starting at 0x7C4 within the same record. */
struct RecD800F2C40 {
    char pad[0xBF5];
    u8 field_bf5; /* 0xBF5 */
    char pad2[0xE20 - 0xBF5 - 1];
};

extern struct RecD800F2C40 D_800F2C40[];

u16 func_80058EC0(s32 idx) {
    u8 sub = D_800F2C40[idx].field_bf5;
    {
        u8 *base = (u8 *)D_800F2C40;
        return *(u16 *)(idx * 0xE20 + sub * 118 + base + 0x7C4);
    }
}
