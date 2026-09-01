#include "../types.h"

extern void func_80039F90(void *);
void func_80039FD4(u8 *object)
{
    *(s8 *)(object + 0x30) = -1;
    func_80039F90(object);
}
