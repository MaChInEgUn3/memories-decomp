#include "../types.h"

extern s32 func_8003F70C(void);
extern void Util_CopyWords(void *, void *, s32);
extern void func_8003D0F4(void *);
extern u8 gDuel_awPlayerDeck[], D_801D3200[];
s32 func_8003F810(void) {
    s32 r = func_8003F70C();
    if (r != 0) {
        if (r == 1) {
            u8 *p = gDuel_awPlayerDeck;
            Util_CopyWords(p, D_801D3200, 0x680);
            func_8003D0F4(p);
        }
        return r;
    }
    return 0;
}
