#include "../types.h"

extern int gAiScript_aMemory[];typedef struct{int first,addend,result;}State;extern State gAiScript_State;extern int func_8007058C(void),func_800705AC(void);void AiScript_JumpGreater(void){int a=func_8007058C(),b=func_8007058C(),result=func_800705AC();register int*values=gAiScript_aMemory;if(values[a]>values[b]){register State*s=&gAiScript_State;result+=s->addend;s->result=result;}}
