#include "../types.h"

typedef struct {
    unsigned char value;
    unsigned char pad1[23];
} Entry24;

extern Entry24 *D_8009B458;

void func_8004B6E8(unsigned char index, int value)
{
    register Entry24 *entries = D_8009B458;

    entries += index;

    entries->value = value;
}
