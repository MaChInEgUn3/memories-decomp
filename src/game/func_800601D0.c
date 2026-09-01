#include "../types.h"

typedef struct{int key,value;}Pair;extern Pair D_800F5918[80];extern void func_80089E20(void);int func_800601D0(void*key){register Pair*table asm("$3");register int high asm("$2");int i;asm("lui %0,%%hi(D_800F5918)\n\taddiu %1,%0,%%lo(D_800F5918)":"=r"(high),"=r"(table));if(key!=func_80089E20)goto start;return-1;found:return table->value;start:i=0;loop:if(table->key==(int)key)goto found;i++;if(i<80){table++;goto loop;}return-1;}
