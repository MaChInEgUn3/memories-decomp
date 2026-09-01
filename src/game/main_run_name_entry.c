#include "../types.h"

extern unsigned char D_8009B26C, D_8009B269;
extern void func_8003BBF8(void), func_801683EC(void);
extern int func_80169C08(void);
void Main_RunNameEntry(void) {
    unsigned char flags = D_8009B26C;
    unsigned char value;
    if ((flags & 0x40) == 0) {
        D_8009B26C = flags | 0x40;
        func_8003BBF8();
        func_801683EC();
    }
    if (func_80169C08()) {
        value = D_8009B269;
        __asm__ volatile("nop");
        D_8009B26C = value;
    }
}
