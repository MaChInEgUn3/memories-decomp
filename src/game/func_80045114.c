#include "../types.h"
#include "sound.h"

extern void func_8004503C(s16, s32, s32);
extern void func_80045BE8(u8 *);

void func_80045114(void) {
    SDValue *p = g_SDValue;
    s32 count;

    if ((p->flags_004A & 0x80) == 0) {
        return;
    }
    count = p->command_count;
    if (p->commands[count].command == 0x11) {
        return;
    }
    if (count > 0) {
        if (p->commands[count - 1].command == 0x11) {
            return;
        }
        if (count >= 2) {
            if (p->commands[count - 2].command == 0x11) {
                return;
            }
        }
    }
    func_8004503C(-0x20, 0, 1);
    {
        u8 local[0x30];
        local[0] = 0x11;
        func_80045BE8(local);
    }
}
