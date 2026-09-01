#include "../types.h"

extern void func_80076ED0(int, int);
extern int func_80077090(int);

void func_80047C70(int value)
{
    int count;
    for (count = 0; count < 256; count++) {
        func_80076ED0(0, value);
        if (func_80077090(value) == 0)
            break;
    }
}
