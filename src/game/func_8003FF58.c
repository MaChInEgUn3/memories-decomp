#include "../types.h"

extern void func_80047430(int, int);

void func_8003FF58(int value)
{
    if (value > 0) {
        value = -value;
    }
    func_80047430((short)value, 0);
}
