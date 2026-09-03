#include "../types.h"

extern s32 func_80036D3C(void *);
extern void func_8003FF88(u16);
extern void SD_SEPlayFull(u16);
extern u16 D_8009B33C;
extern s32 D_8009B350;

void DuelEffect_PlaySoundCommand(u8 *object) {
    u32 value = func_80036D3C(object);

    value &= 0xFFFF;
    if (value & 0x8000) {
        func_8003FF88((u16)value);
        D_8009B33C = func_80036D3C(object);
        object[0x51] = 0x11;
        D_8009B350 = 1;
    } else {
        SD_SEPlayFull((u16)value);
    }
}
