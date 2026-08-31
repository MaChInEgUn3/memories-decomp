typedef unsigned int u32;extern u32 D_8009AF64[2];
void func_8003CE74(void){register u32*p asm("$6")=D_8009AF64;register u32 x asm("$3");register u32 n asm("$2");u32 y,a;x=p[0];y=p[1];n=(y<<31)|(x>>1);n^=x<<12;a=y+(x&1);y+=a;p[1]=y;p[0]=n^(n>>20);}
