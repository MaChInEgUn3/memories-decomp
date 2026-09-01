#include "../types.h"

typedef struct {
    unsigned char pad0[0xE06];
    unsigned short value;
    unsigned char padE08[0x18];
} EntryE20;

extern EntryE20 D_800F2C40[];

int func_80058E94(int index)
{
    return D_800F2C40[index].value >> 4;
}
