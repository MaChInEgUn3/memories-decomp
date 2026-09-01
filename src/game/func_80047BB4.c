#include "../types.h"

extern u8 *g_SDValue;
extern void func_80076ED0(int, int);
extern void func_8004763C(void);
extern void func_80047788(u16);

void func_80047BB4(u16 *items, int count)
{
    int i;
    func_80076ED0(0, 0x00F00000);
    func_8004763C();
    *(u16 *)(g_SDValue + 0x40) |= 2;
    for (i = 0; i < count; i++) {
        if (items[i] != 0xFFFF)
            func_80047788(items[i]);
    }
}
