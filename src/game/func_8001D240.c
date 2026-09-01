#include "../types.h"

typedef struct{char p0[8];u16 flags;char pA[0x17];u8 current,mode;char p23;void*callback;s16 dx,dy;char p2C[0x3E];u8 index;char p6B;u8 active;}Object;
typedef struct{char p[0x16];u16 flags;char tail[4];}Entry;extern Entry D_801A7AD8[];extern int func_80042B98(Object*);
void func_8001D240(Object*o)
{
 if(!func_80042B98(o)){o->flags|=4;if(!o->mode){o->dx=-8;o->dy=0xC0;}else{o->dx=8;o->dy=0;}}
 o->mode+=o->dx;if(o->mode<0xC0){Entry*e=&D_801A7AD8[o->index];e->flags|=0x800;o->mode=o->dy;
  if(!o->mode){e->flags&=~0x800;if(!o->current)o->flags&=~4;}o->active=0;o->callback=0;}
}
