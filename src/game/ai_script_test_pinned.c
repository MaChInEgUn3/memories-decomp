typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { u8 pad[25]; s8 value; u8 tail[6]; } Rec32;
extern s32 gAiScript_aMemory[];
extern Rec32 D_800E9FF0[];
extern u8 D_8009B1D5[];
extern s32 AiScript_ReadByte(void);
void AiScript_TestPinned(void) {
    s32 *p = gAiScript_aMemory;
    s32 i = p[AiScript_ReadByte()];
    p[AiScript_ReadByte()] = D_800E9FF0[(D_8009B1D5[0] ^ 1) ^ i].value != 0;
}
