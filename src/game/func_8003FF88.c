#include "../types.h"

extern void SD_SEPlay(unsigned int, int, int);

void func_8003FF88(unsigned int value)
{
    SD_SEPlay((value & 0xFFFF) | 0x8000, 0xFF, 0);
}
