#include "../types.h"

extern char D_8009B104[1];
extern int D_8009B130, D_8009B0F4, D_8009B134, D_8009B138;
extern u8 D_8009B114;
extern void func_8007B468();
extern void func_8007DE38(int);
extern void func_8007DD50(void *, int);
extern void func_80013C28(void);

void func_800140A0(u8 event)
{
    if (event == 5) {
        D_8009B130++;
        func_8007B468(0xA0, D_8009B104, 6, func_800140A0, -1);
    } else if (event == 2) {
        func_8007DE38(1);
        func_8007DD50(func_80013C28, -1);
        D_8009B114 = 0;
        D_8009B138 = 0;
        D_8009B0F4 &= ~0x400;
    }
}
