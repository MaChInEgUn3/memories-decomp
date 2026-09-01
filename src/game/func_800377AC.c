#include "../types.h"

extern u8 D_8009B357;

void func_800377AC(u8 *value)
{
    if (D_8009B357 == 0) {
        value[0x51] = 0;
    }
}
