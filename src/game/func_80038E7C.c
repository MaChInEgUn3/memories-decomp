#include "../types.h"

extern int D_8009B350;
void func_80038E7C(u8*o){u16 f;o[0x58]--;if(*(s8*)(o+0x58)<0){f=*(u16*)(o+0x34);D_8009B350=1;f|=0x2000;*(u16*)(o+0x34)=f;}}
