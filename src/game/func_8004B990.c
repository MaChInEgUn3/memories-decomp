#include "../types.h"

extern unsigned char *D_8009B458;
extern void func_800738B0(void);
extern void func_80073A54(unsigned int);
extern void func_800738C0(void);
void func_8004B990(void)
{
    D_8009B458[0x503] = 1;
    func_800738B0();
    func_80073A54(0xF2000002);
    func_800738C0();
    D_8009B458[0x500] = 0;
}
