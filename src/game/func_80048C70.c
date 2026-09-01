#include "../types.h"

void func_80048C70(unsigned int *dst, unsigned int *src)
{
    unsigned int i;
    for (i = 0; i < 64; i++) {
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
        *dst++ = *src++;
    }
}
