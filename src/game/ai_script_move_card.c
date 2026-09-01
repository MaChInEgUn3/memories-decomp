#include "../types.h"

typedef struct{unsigned char pad[6];unsigned short flags;unsigned char tail[4];}Record;extern int gAiScript_aMemory[];extern Record gDuel_aActiveCards[];extern int AiScript_ReadByte(void);void AiScript_MoveCard(void){register int*values=gAiScript_aMemory;int index=AiScript_ReadByte();{int value=values[index];gDuel_aActiveCards[value].flags|=0x4000;}}
