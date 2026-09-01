#include "../types.h"

extern unsigned int D_8009B400;
extern void func_80047314(unsigned int);

void func_8003FF08(unsigned int value)
{
    unsigned int command = value | 0x7000;

    func_80047314(command & 0xFFFF);
    D_8009B400 = command;
}
