#include "../types.h"

extern u8 D_800EFE48[];

void *func_80042B40(int value)
{
    u8 *object = D_800EFE48;
    int count = 96;
    u8 *field = object + 108;
    do {
        if ((*(u16 *)(field - 100) & 0x80) &&
            ((field[0] & 0xF) == value))
            return object;
        field += 112;
        count--;
        object += 112;
    } while (count != 0);
    return 0;
}
