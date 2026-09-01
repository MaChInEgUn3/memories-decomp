#include "../types.h"

extern unsigned char D_8009B26C, D_8009B269;
extern void func_80030198(void);
extern void func_80031084(void);
void Main_RunDebugMenu(void) {
    unsigned char flags = D_8009B26C;
    if ((flags & 0x40) == 0) {
        D_8009B26C = flags | 0x40;
        func_80030198();
    } else {
        func_80031084();
        if ((D_8009B26C & 0x40) == 0) D_8009B269 = 0;
    }
}
