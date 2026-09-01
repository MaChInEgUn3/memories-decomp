#include "../types.h"

typedef struct{char p0[8];u16 flags;char pA[0x17];u8 current,mode;char p23;void*callback;s16 x,y,target,step;int oldPosition;char p34[0x2C];s16 speed;char p62[0xA];u8 active;}Object;
extern int func_80042B98(Object*);extern void func_80043178(Object*),func_8004318C(Object*,int,int,int);
void func_8001D3C4(Object*o)
{
 if(!func_80042B98(o)){if(o->target!=o->current)o->flags|=4;o->step=o->speed;func_80043178(o);o->speed=0;}
 if(o->current!=o->target)o->current+=0x80/o->step;
 func_8004318C(o,o->x,o->y,o->speed);o->speed+=0x800/o->step;
 if(o->speed>=0x800){u8 target=o->target;int position=*(int*)&o->x;o->current=target;o->oldPosition=position;if(!(target&0xFF))o->flags&=~4;o->active=0;o->callback=0;}
}
