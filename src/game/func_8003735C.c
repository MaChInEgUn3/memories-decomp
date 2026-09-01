#include "../types.h"

extern unsigned char D_800EB288[];
int func_8003735C(unsigned char*object){register unsigned int index __asm__("$2")=*(unsigned short*)(object+0x5C);register unsigned int count __asm__("$4")=*(unsigned short*)(object+0x5E);register unsigned char*entry __asm__("$3")=D_800EB288+index*28;if(count){entry+=0x13;do{if((entry[-2]&0x80)==0)return 0;if(entry[0])return 1;count--;entry+=28;}while(count);}return 0;}
