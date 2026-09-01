#include "../types.h"

extern int gAiScript_aMemory[],AiScript_ReadByte(void);extern unsigned char gAiScript_State[];void AiScript_StartCombo(void){int dest=AiScript_ReadByte(),i;for(i=0;i<5;i++){int v=gAiScript_State[0x38+i];if((unsigned)(v-1)<10){gAiScript_aMemory[dest]=v;return;}}gAiScript_aMemory[dest]=0;}
