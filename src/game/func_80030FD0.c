#include "../types.h"

extern u8 D_800E9DC0[];
extern void func_80015AD8(void);
extern void func_800403F0(void);
extern void func_80035A64(void);
extern void func_8008FB8C(u8 *, s32) __attribute__((noreturn));

void func_80030FD0(void)
{
    func_80015AD8();
    func_800403F0();
    func_80035A64();
    func_8008FB8C(D_800E9DC0, 2);
}
