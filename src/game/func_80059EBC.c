#include "../types.h"

extern int func_8005F174(void);
extern int func_8005F18C(void);
extern void func_80052D2C(int, int, int, int);
void func_80059EBC(int value)
{
    int state = func_8005F174();
    if (state != 1 || func_8005F18C() != state)
        func_80052D2C(value, 0, 0, 0);
}
