#include "../types.h"

extern int func_8004BAE4(void *);

int func_8004BC2C(void *input)
{
    void *item = input;
    int first = func_8004BAE4(item);
    int second = func_8004BAE4(item);
    int third = func_8004BAE4(item);
    int fourth = func_8004BAE4(item);
    return (fourth & 0xFF) + ((third & 0xFF) << 8) +
           ((second & 0xFF) << 16) + (first << 24);
}
