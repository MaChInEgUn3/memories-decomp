#include "../types.h"
#include "model.h"

void *func_80059520(int index){ModelSlot*e=&D_800F2C40[index];int mod=e->field_DC0[7]%6;unsigned char*p=e->field_DC0;if(mod!=0&&p[3]==0)p+=4;return p;}
