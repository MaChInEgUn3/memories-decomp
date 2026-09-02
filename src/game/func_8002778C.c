#include "../types.h"
#include "duel_card.h"

typedef struct Child{char p[0x6A];u8 index;}Child;typedef struct{Child*ptr;}Source;
extern u8 D_8009B1D5,D_800907D8[];extern int func_8001EFD4(Child*,Child*);
int func_8002778C(Source*source)
{
 int count=0;int slot=5;do{int position=slot+D_8009B1D5*20;DuelCardRecord*e=&D_801A7AD8[D_800907D8[position]];if(e->flags&0x8000){count++;if(func_8001EFD4(source->ptr,e->object)>0)return ((Child*)e->object)->index;}slot++;}while(slot<10);
 if(count==0)return D_800907D8[D_8009B1D5*20+7];return-1;
}
