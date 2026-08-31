extern volatile int D_8009B0F4,D_8009B134;extern void func_800143DC(void),func_80015010(void);
void func_800144B8(void){D_8009B0F4&=0x60;if((D_8009B0F4&0x20)&&!(D_8009B0F4&0x40)){func_800143DC();if(D_8009B134){int v=0x80;if((D_8009B0F4&0x10)&&(D_8009B0F4&0x80000))func_80015010();D_8009B134=v;}}else D_8009B134=0;}
