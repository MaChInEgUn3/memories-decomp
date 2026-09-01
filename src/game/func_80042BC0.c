#include "../types.h"

extern void func_8004036C(void *);

void func_80042BC0(unsigned char *object)
{
    int value = object[12] - *(short *)(object + 96);
    if (value > 0) {
        object[14] = value;
        object[13] = value;
        object[12] = value;
    } else {
        func_8004036C(object);
    }
}
