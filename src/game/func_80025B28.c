#include "../types.h"

typedef struct Obj{char p[0x22];u8 timer;char p23;void*cb;char p28[0x3F];u8 mark;char p68[2];u8 index;char p6b;u8 active;}Obj;
typedef struct{char p[0x16];u16 flags;char p18[4];}Entry;extern Entry D_801A7AD8[];extern void func_80018080(Obj*);
void func_80025B28(Obj*o){o->timer+=8;if(!(o->active&0x80)&&o->timer>=40){o->active|=0x80;D_801A7AD8[o->index].flags&=~0x2000;o->mark=0;}
 if(o->timer<64){o->timer=0;o->active=0;o->cb=0;D_801A7AD8[o->index].flags&=~0x3400;func_80018080(o);}}
