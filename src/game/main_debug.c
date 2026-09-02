#include "../types.h"

extern u8 D_8009B269;
extern u8 D_8009B26C;

extern void func_8002CD8C(void);
extern void func_80030198(void);
extern void func_80031084(void);

void func_8002CDE8(void)
{
    func_8002CD8C();
}

void Main_RunDebugMenu(void)
{
    u8 flags = D_8009B26C;

    if ((flags & 0x40) == 0) {
        D_8009B26C = flags | 0x40;
        func_80030198();
    } else {
        func_80031084();
        if ((D_8009B26C & 0x40) == 0)
            D_8009B269 = 0;
    }
}
