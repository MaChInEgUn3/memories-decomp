typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


typedef struct { s16 value; u8 pad[10]; } Rec12;
extern Rec12 gDuel_aActiveCards[];
extern s32 gAiScript_aMemory[];
extern s32 AiScript_ReadByte(void);
void AiScript_LoadDeckSize(void) {
    s32 k = AiScript_ReadByte();
    s32 count = 0;
    s32 i;
    for (i = 0xB; i < 0x38; i++)
        if (gDuel_aActiveCards[i].value != 0) count++;
    gAiScript_aMemory[k] = count - 5;
}
