#include "../types.h"

extern void func_80089060(void *, void *);
extern void func_80087670(void *, void *);
void func_8005922C(unsigned char *object, void *source)
{
    func_80089060(object + 0x44, object + 4);
    if (source != 0) func_80087670(object + 4, source);
    *(int *)object = 0;
}
