#include "../types.h"

typedef struct { unsigned char pad[0xE0D]; unsigned char type; unsigned char pad2[8]; unsigned char state; unsigned char tail[9]; } Entry;
extern Entry D_800F2C40[]; extern void func_80059700(int,int);
void func_8005969C(int index,int type)
{
    Entry *e=&D_800F2C40[index]; if((unsigned)(type-4)>=29)type=8; e->type=type; if(e->state==0x3e)func_80059700(index,1);
}
