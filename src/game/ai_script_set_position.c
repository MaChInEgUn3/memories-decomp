typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 gAiScript_aMemory[];
extern u8 D_800EAE8E[];
extern s32 AiScript_ReadByte(void);

void AiScript_SetPosition(void)
{
    s32 *p = gAiScript_aMemory;
    s32 v;

    v = p[AiScript_ReadByte()];
    D_800EAE8E[0] = v;
}
