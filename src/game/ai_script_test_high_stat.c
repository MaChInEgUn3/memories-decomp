#include "../types.h"

extern int gAiScript_aMemory[],gDuel_adwCardStats[],AiScript_ReadByte(void),Duel_GetBaseCardStat(int,int);void AiScript_TestHighStat(void){register int*values=gAiScript_aMemory;int value=values[AiScript_ReadByte()];int dest=AiScript_ReadByte(),result;if(((gDuel_adwCardStats[value-1]>>26)&31)<20){int a=Duel_GetBaseCardStat(value,0),b=Duel_GetBaseCardStat(value,1);result=!(b<a);}else result=0;gAiScript_aMemory[dest]=result;}
