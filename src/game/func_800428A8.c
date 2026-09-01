#include "../types.h"

extern void func_800404CC(void *, int, int, int, int, int, int, int);

void func_800428A8(void *object, int a1, int a2, int a3, int a4, int a5,
                   int a6, int a7, int a8)
{
    *(int *)((char *)object + 0x54) = a8;
    func_800404CC(object, a1, a2, a3, a4, a5, a6, a7);
}
