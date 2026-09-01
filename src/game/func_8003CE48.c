#include "../types.h"

extern volatile unsigned short D_8009B394;
extern volatile unsigned short D_8009B398;
extern volatile unsigned short D_8009B39E;
extern volatile unsigned short D_8009B3A0;
extern volatile unsigned short D_8009B3A4;
extern volatile unsigned short D_8009B3AC;

void func_8003CE48(void)
{
    unsigned short value;

    value = D_8009B3AC;
    __asm__ volatile("nop");
    D_8009B3A4 = value;
    value = D_8009B3A0;
    __asm__ volatile("nop");
    D_8009B398 = value;
    value = D_8009B39E;
    __asm__ volatile("nop");
    D_8009B394 = value;
}
