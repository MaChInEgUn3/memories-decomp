typedef unsigned char u8;typedef signed char s8;extern void func_8002CCE4(int);
void func_80038AB0(u8*o){register unsigned int v asm("$3");register int n asm("$16");u8**p;u8*q;p=&((u8**)o)[*(s8*)(o+0x58)];q=*p;v=*q++;n=v;*p=q;if(n>0){func_8002CCE4(n+0x1F);func_8002CCE4(n+0x6E0);}}
