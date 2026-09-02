#include "../types.h"

extern int D_800F5B98[];typedef struct{int first,addend,result;}State;extern State D_800F5BE8;extern int func_8007058C(void),func_800705AC(void);void AiScript_JumpGreater(void){int a=func_8007058C(),b=func_8007058C(),result=func_800705AC();register int*values=D_800F5B98;if(values[a]>values[b]){register State*s=&D_800F5BE8;result+=s->addend;s->result=result;}}
