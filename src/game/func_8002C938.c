#include "../types.h"

typedef struct{unsigned int value;unsigned char pad[0x12];unsigned short flags;unsigned char rest[4];}Entry;extern unsigned char D_8009B1D5[];extern Entry D_801A7AD8[];
void func_8002C938(unsigned int*output,int alternate){register int base __asm__("$6")=D_8009B1D5[0]?5:20;register int scaled __asm__("$3");register Entry*entry __asm__("$3");if(alternate)base+=5;scaled=base<<3;scaled-=base;scaled<<=2;entry=(Entry*)((unsigned char*)D_801A7AD8+scaled);base=0;for(;base<5;base++,entry++)if(entry->flags&0x8000)*output++=entry->value;*output=0;}
