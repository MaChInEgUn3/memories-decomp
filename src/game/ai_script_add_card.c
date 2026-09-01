typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 gAiScript_aMemory[];
extern u8 gAiScript_State[];
extern s32 AiScript_ReadByte(void);
void AiScript_AddCard(void) {
    s32 *p = gAiScript_aMemory;
    u8 *q;
    s32 v;
    s32 i;
    v = p[AiScript_ReadByte()];
    q = gAiScript_State;
    for (i = 0; i < 0x20; i++) {
        u16 c = *(u16 *)(q + i * 2 + 0x3E);
        if (c == v) return;
        if (c == 0) { *(u16 *)(q + i * 2 + 0x3E) = v; return; }
    }
}
