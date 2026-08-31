typedef unsigned char u8; typedef unsigned short u16; extern int func_80037C74(void*); extern int D_8009B350; extern void (*D_8009B340)(void*);
void func_80038E1C(u8*o){o[0x56]++;*(u16*)(o+0x38)=0x1000;if(func_80037C74(o))o[0x51]=4;D_8009B350=1;if(D_8009B340)D_8009B340(o);}
