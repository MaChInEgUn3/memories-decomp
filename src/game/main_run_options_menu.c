extern unsigned char D_8009B26C,D_8009B269;
extern void func_8003C2B4(void),func_8003C628(void),func_80015A00(void),func_8003FF34(void);
extern int func_8003C8CC(void);
void Main_RunOptionsMenu(void){unsigned char flags=D_8009B26C;if((flags&0x40)==0){D_8009B26C=flags|0x40;func_8003C2B4();func_8003C628();func_80015A00();}if(func_8003C8CC()==0){unsigned char value;func_8003FF34();value=D_8009B269;__asm__ volatile("nop");D_8009B26C=value;}}
