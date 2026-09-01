typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 gAiScript_aMemory[];
extern s32 AiScript_ReadByte(void);
extern s32 Duel_CheckRitual(s32, s32);
void AiScript_CheckRitual(void) {
    s32 *p = gAiScript_aMemory;
    s32 v = p[AiScript_ReadByte()];
    s32 k = AiScript_ReadByte();
    if (Duel_CheckRitual(0, v) != 0) p[k] = 1;
    else p[k] = 0;
}
