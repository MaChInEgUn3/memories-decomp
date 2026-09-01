#include "../types.h"

typedef struct {
    u8 pad_00[0x11];
    u8 field_11;
    u8 field_12;
    u8 pad_13[9];
} Entry28;
extern Entry28 D_800EB288[];
void func_80035DB8(int value)
{
    int remaining = 0x26C;
    register Entry28 *base asm("$2");
    u8 *entry;
    value++;
    base = D_800EB288;
    asm("" : "+r"(base));
    entry = &base->field_11;
    do {
        if (entry[1] == value) {
            entry[0] = 0;
        }
        entry += sizeof(Entry28);
    } while (--remaining != 0);
}
