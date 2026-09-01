#include "../types.h"

extern int func_80036D3C(void *);
void func_80038388(u8 *object)
{
    *(u16 *)(object + 0x38) = func_80036D3C(object);
}
