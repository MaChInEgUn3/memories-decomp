typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern s32 gAiScript_aMemory[];
extern s32 gDuel_adwCardStats[];
extern s32 AiScript_ReadByte(void);
void AiScript_LoadCardType(void) {
    s32 *p = gAiScript_aMemory;
    s32 i = p[AiScript_ReadByte()] - 1;
    p[AiScript_ReadByte()] = (gDuel_adwCardStats[i] >> 26) & 0x1F;
}
