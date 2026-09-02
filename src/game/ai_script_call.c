#include "../types.h"
#include "ai.h"

extern int AiScript_ReadShort(void);
extern void func_8008E870();

extern AiScriptState gAiScript_State;
extern char D_800118AC[]; /* "ERROR:Sub Routine Nest Over !!\n" */
extern char D_8009B084[]; /* "%s:%d\n" */
extern char D_800118CC[]; /* "src/hirata/H_mctrl1.c" */

/* Pushes the current script cursor onto its return stack; if the stack is full
   (8 entries), prints an error and hangs (original panic-on-overflow
   handler). Either way, ends by folding a freshly-read relative offset into
   the script cursor. */
void AiScript_Call(void) {
    s32 val = AiScript_ReadShort();

    if (gAiScript_State.return_depth < 8) {
        gAiScript_State.return_stack[gAiScript_State.return_depth] =
            gAiScript_State.script_cursor;
        gAiScript_State.return_depth =
            gAiScript_State.return_depth + 1;
    } else {
        func_8008E870(D_800118AC);
        func_8008E870(D_8009B084, D_800118CC, 0x17B);
        for (;;)
            ;
    }

    {
        AiScriptState *state = &gAiScript_State;
        val += (s32)state->script_base;
        state->script_cursor = (u8 *)val;
    }
}
