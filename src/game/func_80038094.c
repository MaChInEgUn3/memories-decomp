#include "../types.h"

extern void func_80038024(void *, int);
void func_80038094(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    func_80038024(object, *(*stream)++);
}
