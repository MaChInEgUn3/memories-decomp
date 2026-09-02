#include "../types.h"

extern void func_8008E870();

/* Same struct as init_duel_buffers.c's D_800F5BE8 (f0/f4/f8 match), plus a
   byte count at 0x14 and an item stack starting at 0x18. */
struct Big {
    s32 f0;
    s32 f4;
    s32 f8;
    u8 pad2[0x14 - 0xC];
    u8 count; /* 0x14 */
    u8 pad3[3];
    s32 items[1]; /* 0x18 */
};

extern struct Big gAiScript_State;
extern char D_800118E4[]; /* "ERROR:Can't Return From Routine !!\n" */
extern char D_8009B084[]; /* "%s:%d\n" */
extern char D_800118CC[]; /* "src/hirata/H_mctrl1.c" */

/* Pops the top of D_800F5BE8's item stack into f8; if the stack is already
   empty, prints an error and hangs (original panic-on-underflow handler). */
void AiScript_Return(void) {
    u8 count = gAiScript_State.count;
    if (count != 0) {
        count = count - 1;
        gAiScript_State.count = count;
        gAiScript_State.f8 = gAiScript_State.items[count];
        return;
    }
    func_8008E870(D_800118E4);
    func_8008E870(D_8009B084, D_800118CC, 0x193);
    for (;;)
        ;
}
