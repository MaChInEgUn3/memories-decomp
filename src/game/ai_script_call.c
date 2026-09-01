typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern int AiScript_ReadShort(void);
extern void func_8008E870();

/* Same struct as init_duel_buffers.c's gAiScript_State (f0/f4/f8 match), plus a
   byte count at 0x14 and an item stack starting at 0x18 (see
   pop_item_or_assert.c, the matching pop operation). */
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
extern char D_800118AC[]; /* "ERROR:Sub Routine Nest Over !!\n" */
extern char D_8009B084[]; /* "%s:%d\n" */
extern char D_800118CC[]; /* "src/hirata/H_mctrl1.c" */

/* Pushes gAiScript_State.f8 onto its item stack; if the stack is already full
   (8 entries), prints an error and hangs (original panic-on-overflow
   handler, the push-side sibling of pop_item_or_assert.c). Either way,
   ends by folding a freshly-read value into f8. */
void AiScript_Call(void) {
    s32 val = AiScript_ReadShort();

    if (gAiScript_State.count < 8) {
        gAiScript_State.items[gAiScript_State.count] = gAiScript_State.f8;
        gAiScript_State.count = gAiScript_State.count + 1;
    } else {
        func_8008E870(D_800118AC);
        func_8008E870(D_8009B084, D_800118CC, 0x17B);
        for (;;)
            ;
    }

    {
        struct Big *p = &gAiScript_State;
        val += p->f4;
        p->f8 = val;
    }
}
