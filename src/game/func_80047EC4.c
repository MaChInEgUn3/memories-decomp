#include "../types.h"
#include "sound.h"

extern void func_80076ED0(int, int);
extern void func_800773C4(void *);

void func_80047EC4(void)
{
    int count = 0;
    int total;
    do {
        func_80076ED0(0, 0x00F00000);
        func_800773C4(g_SDValue->field_15D8);
        total = g_SDValue->field_15EF + g_SDValue->field_15ED +
                g_SDValue->field_15EE + g_SDValue->field_15EF;
        count++;
    } while (total != 0 && count < 24);
}
