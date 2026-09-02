#include "../types.h"
#include "model.h"

typedef struct{unsigned char b[8];}__attribute__((packed))Bytes8;void func_80059000(int index,short*out){register ModelSlot*e=&D_800F2C40[index];register unsigned char*src=e->field_CF8;int v;*(Bytes8*)out=*(Bytes8*)e->field_DC8;v=src[7];if(v)out[0]=v<<4;v=src[8];if(v)out[1]=v<<4;v=src[9];if(v)out[2]=v<<4;out[3]=0;if(out[0]>0)out[3]=out[0];if(out[3]<out[1])out[3]=out[1];if(out[3]<out[2])out[3]=out[2];}
