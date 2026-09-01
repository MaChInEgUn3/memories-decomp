#include "../types.h"

typedef void (*AiScriptHandler)(void);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad10[4];
    u8 count;
    u8 pad15[3];
    s32 items[1];
} AiScriptState;

extern u8 D_800EAE88[];
extern s32 gAiScript_aMemory[];
extern AiScriptState gAiScript_State;
extern AiScriptHandler gAiScript_apfnCommand[];

extern s32 AiScript_ReadByte(void);
extern s32 func_80074170(s32);
extern void func_8008E360(void *, s32);
extern void AiScript_EndHand(void);
extern void AiScript_EndField(void);
extern void AiScript_PlayFieldCard(void);

void AiScript_Init(void *arg0)
{
    u8 *state = (u8 *)&gAiScript_State;

    func_8008E360(state, 0xD4);
    func_8008E360(D_800EAE88, 0xC);
    func_8008E360(gAiScript_aMemory, 0x50);
    if (arg0 == 0)
        state[0] = 1;
    *(void **)(state + 4) = arg0;
    *(void **)(state + 8) = arg0;
}

s32 AiScript_Run(void)
{
    for (;;) {
        s32 idx;
        AiScriptHandler handler;

        gAiScript_State.fC = gAiScript_State.f8;
        idx = AiScript_ReadByte();
        gAiScript_apfnCommand[idx]();
        handler = gAiScript_apfnCommand[idx];

        if (handler == AiScript_EndHand)
            return 1;
        if (handler == AiScript_EndField)
            return 3;
        if (handler == AiScript_PlayFieldCard)
            return 2;
        if (func_80074170(1) >= 0xF0)
            break;
    }

    return 0;
}
