#include "../types.h"
#include "duel_card.h"

extern unsigned char D_8009B1D5[];
void func_8002C938(unsigned int*output,int alternate){register int base __asm__("$6")=D_8009B1D5[0]?5:20;register int scaled __asm__("$3");register DuelCardRecord*entry __asm__("$3");if(alternate)base+=5;scaled=base<<3;scaled-=base;scaled<<=2;entry=(DuelCardRecord*)((unsigned char*)D_801A7AD8+scaled);base=0;for(;base<5;base++,entry++)if(entry->flags&0x8000)*output++=(u32)entry->object;*output=0;}
