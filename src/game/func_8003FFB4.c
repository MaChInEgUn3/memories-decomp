#include "../types.h"

extern void func_80045334(unsigned int);

void func_8003FFB4(unsigned int value)
{
    func_80045334((value & 0xFFFF) | 0x8000);
}
