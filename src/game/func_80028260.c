#include "../types.h"

int func_80028260(int value)
{
    if (value & 0x80) {
        return (value & 0x7F) + 0xF;
    }
    return value;
}
