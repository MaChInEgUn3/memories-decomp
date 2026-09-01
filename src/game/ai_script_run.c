#include "../types.h"

typedef void (*Handler)(void);
struct Big {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    u8 pad2[4];
    u8 count;
    u8 pad3[3];
    s32 items[1];
};
extern s32 AiScript_ReadByte(void);
extern s32 func_80074170(s32);
extern Handler gAiScript_apfnCommand[];
extern void AiScript_EndHand(void);
extern void AiScript_EndField(void);
extern void AiScript_PlayFieldCard(void);
extern struct Big gAiScript_State;

s32 AiScript_Run(void) {
    for (;;) {
        s32 idx;
        Handler h;

        gAiScript_State.fC = gAiScript_State.f8;
        idx = AiScript_ReadByte();
        gAiScript_apfnCommand[idx]();
        h = gAiScript_apfnCommand[idx];

        if (h == AiScript_EndHand) {
            return 1;
        }
        if (h == AiScript_EndField) {
            return 3;
        }
        if (h == AiScript_PlayFieldCard) {
            return 2;
        }

        if (func_80074170(1) >= 0xF0) {
            break;
        }
    }

    return 0;
}
