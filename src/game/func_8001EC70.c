#include "../types.h"

typedef struct{char p[0x24];void*cb;s16 x,y,dy,z;char p30[0x30];s16 speed;char p62[0xA];u8 active;}Obj;
extern int func_80042B98(Obj*);extern void func_80043178(Obj*),func_8004318C(Obj*,int,int,int);
void func_8001EC70(Obj*o){if(!func_80042B98(o)){func_80043178(o);o->speed=0;o->z=0;}func_8004318C(o,o->x,o->y,o->speed);o->speed+=0x800/o->dy;if(o->speed>=0x800){o->active=0;o->cb=0;}}
