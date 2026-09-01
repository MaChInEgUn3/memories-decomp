#include "../types.h"

extern void func_80036C14(void *);
void func_80038024(u8 *o){ o[0x34] = o[0x34]; *(u16*)(o+0x34)|=0x80; func_80036C14(o); *(u16*)(o+0x34)&=0xFF7F; *(u16*)(o+0x38)+=0x10; }
