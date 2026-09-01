#include "../types.h"

extern int func_8005BE3C(void);
extern void func_8005BB7C(int);

int func_8005C530(void)
{
    int result = func_8005BE3C();

    if (result != 0) {
        func_8005BB7C(0);
    }
    return result;
}
