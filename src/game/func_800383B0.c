#include "../types.h"

extern int func_80036D3C(void *);
void func_800383B0(u8 *object)
{
    object[0x60] = 0;
    object[0x61] = func_80036D3C(object);
}
