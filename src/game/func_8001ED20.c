typedef unsigned char u8;typedef unsigned short u16;typedef signed short s16;
typedef struct{char p0[8];u16 flags;char pA[0x17];u8 current,mode;char p23;void*callback;s16 x,y,denominator,field2E;int oldPosition;char p34[0x2C];s16 speed;char p62[0xA];u8 active;}Object;
extern int func_80042B98(Object*);extern void func_80043178(Object*),func_8004318C(Object*,int,int,int);
void func_8001ED20(Object*o)
{
 if(!func_80042B98(o)){func_80043178(o);o->speed=0;o->field2E=0;}if(o->mode)o->mode+=0x40/o->denominator;
 func_8004318C(o,o->x,o->y,o->speed);o->speed+=0x800/o->denominator;if(o->speed>=0x800){o->oldPosition=*(int*)((char*)o+0x28);o->mode=0;if(!o->current)o->flags&=~4;o->active=0;o->callback=0;}
}
