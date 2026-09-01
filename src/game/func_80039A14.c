#include "../types.h"

extern void func_800393B0(void*);
void func_80039A14(u8*o){*(u16*)(o+0x34)|=0x800;do{func_800393B0(o);}while(!(*(u16*)(o+0x34)&0x2000));}
