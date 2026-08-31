typedef unsigned char u8;typedef unsigned short u16;typedef struct{char p[8];u16 flags;char pA[2];int color;char p10[0x11];u8 a,b;char p23[0x44];u8 mark;char p68[2];u8 index;}Obj;
typedef struct{char p[0x16];u16 flags;char tail[4];}Entry;extern Entry D_801A7AD8[];
void func_80017E3C(Obj*o){register int index asm("$2")=o->index;register int offset asm("$3")=(index*7)*4;Entry*e=(Entry*)((char*)D_801A7AD8+offset);
 if(!(e->flags&0x2000))o->mark=0;o->flags&=~4;if(e->flags&0x1800){o->flags|=4;o->a=0;if(e->flags&0x1000)o->a=0x80;o->b=0;if(e->flags&0x800)o->b=0xC0;}
 o->color=0x808080;if(e->flags&0x4000)o->color=0x404040;}
