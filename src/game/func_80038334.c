typedef unsigned char u8; typedef signed char s8;
void func_80038334(u8 *o){register u8 **p asm("$3");register u8*q asm("$2");register u8 v asm("$5");p=&((u8**)o)[*(s8*)(o+0x58)];q=*p;v=*q++;*p=q;o[0x5A]=v;p=&((u8**)o)[*(s8*)(o+0x58)];q=*p;v=*q++;*p=q;o[0x5B]=v;}
