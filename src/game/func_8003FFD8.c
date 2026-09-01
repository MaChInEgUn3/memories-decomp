#include "../types.h"

extern void func_80047314(unsigned int);

void func_8003FFD8(unsigned int value)
{
    func_80047314((value & 0xFFFF) | 0xA000);
}
