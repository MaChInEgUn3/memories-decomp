#include "../types.h"

typedef struct{char p0[4];u16 width,height;int field8,fieldC,field10,field14,field18,field1C,field20,field24;char p28[4];unsigned int flags;u16 x,y;int field34;char p38[8];int field40;u16 field44;u8 state,substate;}Object;
extern int D_8009B118;extern void func_80013940(Object*,int,int,int);
Object*func_80013998(Object*object,int flags,int field18,int sector,int vertical,int field20,int field40,int length)
{
 object->field18=field18;func_80013940(object,flags,sector,-vertical);object->state=1;object->substate=0;object->field44=0;object->field1C=0;object->field20=field20;object->field40=field40;
 if(length){if(flags&0x1000000)object->field34=length;else{object->field1C=object->field10;if(length<0){object->state=1;object->fieldC=length;object->field8=length;}
  else{flags|=0x10000;object->state=2;object->y=((unsigned int)length)>>16;object->x=length;object->width=0x40;object->height=0x10;object->field8=D_8009B118;object->fieldC=D_8009B118+0x800;}}}
 object->flags=flags;return object;
}
