#include "../types.h"

extern unsigned char*D_8009B290;extern unsigned char*D_8009B274;extern unsigned short D_8009B27C;extern unsigned char D_800EB010[];extern int func_8002E3B4(void);extern void func_80039FD4(void*),func_80039E9C(void),func_80039F44(void*),func_8003B50C(int);
void func_8002EB78(void){unsigned char*o;int first,flags,bit;if(func_8002E3B4()==0){first=*D_8009B290++;flags=*D_8009B290++;bit=flags&0x80;o=D_800EB010+((bit>>7)*0x4C);D_8009B274=o;if(*(signed char*)(o+0x30)>=0)func_80039FD4(o);func_80039E9C();func_80039F44(o);o[0x31]=flags&15;o[0x30]=first;o[0x3C]=bit>>7;o[0x33]=2;if(bit)*(short*)(o+0x34)=0xD8;}func_8003B50C(0);if(D_8009B274[0x33]==0)D_8009B27C=0;}
