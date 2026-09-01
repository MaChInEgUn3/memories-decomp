#include "../types.h"

extern unsigned char D_800117C8;
extern void func_8005B64C(void);
extern void func_80014E1C(int, void *, int, int, void (*)(void), int, int);
void func_8005B85C(void)
{
    func_80014E1C(1, &D_800117C8, 0, 0x73, func_8005B64C, 0, 0);
}
