#include "../types.h"

extern void func_80012D4C(void);
extern int D_8009B0F4;
extern int D_8009B134;
extern unsigned short D_8009B398;

void func_800438B8(int count)
{
    int found = 0;
    for (;;) {
        func_80012D4C();
        if (!found && (((D_8009B0F4 & 0x02000030) | D_8009B134) == 0))
            found = 1;
        if ((D_8009B398 & 0x8C0) && found)
            count = 0;
        count--;
        if (count >= 0)
            continue;
        if (!found) {
            count = 0;
            continue;
        }
        break;
    }
}
