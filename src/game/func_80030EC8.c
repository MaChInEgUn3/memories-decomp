extern unsigned char D_8009B2EB;
extern unsigned char D_8009B3ED[],D_8009B3EA[],D_8009B26C[];
extern int func_8003FCD8(void);
extern void func_8005B85C(void),func_800137E4(void);
void func_80030EC8(void) {
    unsigned char flags=D_8009B2EB;
    int result;
    if((flags&0x80)==0){D_8009B2EB=flags|0x80;D_8009B3ED[0]=0;D_8009B3EA[0]=0;}
    result=func_8003FCD8();
    if(result!=0){
        if(result==1){func_8005B85C();func_800137E4();D_8009B26C[0]=14;}
        D_8009B2EB=0;
    }
}
