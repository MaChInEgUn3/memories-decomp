#include "../types.h"

extern unsigned char D_801D1880[],D_80010384[];extern void func_8003CF14(void*);extern void func_8003F758(void*,int,void*,int);extern void *D_8009B3E0;
void func_8003FE14(void){unsigned char*p=D_801D1880;unsigned char*q=p+0x1000;func_8003CF14(p);func_8003CF14(q);D_8009B3E0=q;func_8003F758(p,0x400,D_80010384,4);}
