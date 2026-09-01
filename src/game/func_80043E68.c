#include "../types.h"

extern void *D_800F2AE0[];
extern void func_800738B0(void);
extern void func_80073870(void *);
extern void func_800738C0(void);

void func_80043E68(void)
{
    void **item = D_800F2AE0;
    int count;
    func_800738B0();
    count = 8;
    do {
        func_80073870(*item++);
        count--;
    } while (count != 0);
    func_800738C0();
}
