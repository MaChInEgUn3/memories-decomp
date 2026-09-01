#include "../types.h"

extern u8 *D_8009B458;
extern void func_8004B854(void);

void func_80049544(void)
{
    int value = *(int *)(D_8009B458 + 0x81C);
    if (value > 0) {
        if (value < 4)
            func_8004B854();
    }
    D_8009B458[0x814] = 1;
}
