#include "../types.h"

extern int func_8004BAE4(int);

int func_8004BCA8(int value)
{
    int high = func_8004BAE4(value);
    int low = func_8004BAE4(value);

    return (low & 0xFF) | ((high & 0xFF) << 8);
}
