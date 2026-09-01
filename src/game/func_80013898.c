#include "../types.h"

extern int D_8009B118;
extern unsigned char D_8009B110;
extern unsigned char D_8009B108;
extern int D_8009B0F4;
extern int D_8009B120;
extern int D_8009B0F0;
extern int D_8009B134;
extern unsigned short D_8009B112;
extern int D_8009B10C;
extern int D_8009B12C;
extern unsigned short D_8009B124;
extern int D_8009B0E8;
extern int D_8009B130;
extern int D_8009B0FC;
extern int func_8007AFA4(void);

void func_80013898(int value)
{
    D_8009B118 = value;
    D_8009B110 = 0;
    D_8009B108 = 0;
    D_8009B0F4 = 0;
    D_8009B120 = 0;
    D_8009B0F0 = 0;
    D_8009B134 = 0;
    D_8009B112 = 0;
    D_8009B10C = 0;
    D_8009B12C = 0;
    D_8009B124 = 0;
    D_8009B0E8 = 0;
    D_8009B130 = 0;
    while (func_8007AFA4() == 0) {
    }
    D_8009B0FC = 1;
}
