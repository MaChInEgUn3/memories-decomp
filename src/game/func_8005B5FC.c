#include "../types.h"

void func_8005B5FC(int *destination, int value, unsigned int count)
{
    while (count-- != 0) {
        *destination++ = value;
    }
}
