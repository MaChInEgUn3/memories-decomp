#include "../types.h"

typedef struct{char p[8];u16 flags;char pA[2];int color;char p10[6];u16 eflags;char p18[9];u8 a,b;char p23[0x44];u8 mark;char p68[2];u8 index;}Obj;
typedef struct{char p[0x16];u16 flags;char tail[4];}Entry;extern Entry D_801A7AD8[];extern void func_80017DB4(Obj*);
void func_80018080(Obj*o){register int index asm("$4")=o->index;register int offset asm("$3")=(index*7)*4;Entry*e=(Entry*)((char*)D_801A7AD8+offset);
 o->b=0;o->flags&=~4;if(e->flags&0x1000)o->b=0x80;o->a=0;if(e->flags&0x800)o->a=0xC0;o->color=0x808080;if(e->flags&0x4000)o->color=0x404040;func_80017DB4(o);if(!(e->flags&0x2000))o->mark=0;}
