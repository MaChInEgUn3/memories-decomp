#include "../types.h"

extern int D_800E9EF0[];

void func_8002CB50(int *destination)
{
    int i;
    int *source;

    i = 0;
    source = D_800E9EF0;
    while (i < 5) {
        *destination++ = *source++;
        i++;
    }
    *destination = 0;
}
