#include "../types.h"

extern int func_8005F174(void);
extern int func_8005F18C(void);
extern short D_800F2B22;
void func_8005A0DC(int value)
{
    int state = func_8005F174();
    if (state != 1 || func_8005F18C() != state) D_800F2B22 = value * 2;
}
