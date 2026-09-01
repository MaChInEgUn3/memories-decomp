#include "../types.h"

typedef struct{short active;unsigned char pad[6];signed char kind;unsigned char tail[3];}Record;extern unsigned char D_800EAE88[6];extern Record gDuel_aActiveCards[];extern int gAiScript_aMemory[],AiScript_ReadByte(void);void AiScript_FindFirstMonster(void){int dest=AiScript_ReadByte(),i;for(i=0;i<5;i++){int id=D_800EAE88[i];if(gDuel_aActiveCards[id].active&&gDuel_aActiveCards[id].kind<20){gAiScript_aMemory[dest]=id;return;}}gAiScript_aMemory[dest]=0;}
