#include "../types.h"

extern void func_80089E20(void),func_80089E40(void),func_80089ED0(void);void*func_800603DC(unsigned int v){if(v==0x2000000)goto a;if(v==0x2000001)goto b;goto d;a:return func_80089E40;b:return func_80089ED0;d:return func_80089E20;}
