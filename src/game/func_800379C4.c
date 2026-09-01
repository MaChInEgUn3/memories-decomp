#include "../types.h"

extern int func_80049120(void *);
void func_800379C4(u8 *object)
{
    if (func_80049120(object) != 1) {
        object[0x51] = 0;
    }
}
