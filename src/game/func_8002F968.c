#include "../types.h"

extern unsigned char *D_8009B290;
extern signed short D_8009B278;
extern unsigned short D_8009B27C;
extern int func_8002E3B4(void);
void func_8002F968(void) {
    if (func_8002E3B4() == 0) {
        unsigned char *p = D_8009B290;
        D_8009B290 = p + 2;
        D_8009B278 = p[0] | (p[1] << 8);
    }
    D_8009B278--;
    if (D_8009B278 <= 0) D_8009B27C = 0;
}
