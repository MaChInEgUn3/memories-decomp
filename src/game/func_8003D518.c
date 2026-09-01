#include "../types.h"

extern u8 D_8009B3C1;
extern s8 D_8009AF76[];
extern s32 func_8004002C(void);
extern u8 *func_800400AC();
extern void func_80042918();
extern void func_800428EC();
extern void func_80042C08();

void func_8003D518(u8 *state)
{
    u8 *object;
    s32 flags;

    if ((D_8009B3C1 & 128) == 0) {
        D_8009B3C1 |= 128;
        object = func_800400AC(func_8004002C(), 6);
        *(s16 *)(object + 48) = 160;
        *(s16 *)(object + 50) = 120;
        *(s16 *)(object + 72) = 128;
        *(s16 *)(object + 74) = 224;
        func_80042918(object);
        func_800428EC(object, (s8)(D_8009AF76[0] - 3));
        *(s32 *)(object + 76) = (s32)func_80042C08;
        *(u8 **)(state + 4) = object;
    }
    flags = D_8009B3C1;
    object = *(u8 **)(state + 4);
    if (flags & 64) {
        D_8009B3C1 = 0;
    } else {
        s32 x = *(u16 *)(object + 72) - 8;
        s32 y = *(u16 *)(object + 74) - 8;
        *(u16 *)(object + 74) = y;
        *(u16 *)(object + 72) = x;
        if ((s16)x <= 0) {
            D_8009B3C1 = flags | 64;
            *(s16 *)(object + 72) = 0;
            *(s16 *)(object + 74) = 64;
        }
    }
}
