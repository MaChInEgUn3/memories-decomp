extern void(*D_800E9DB0[4])(void);extern void(*D_8009B0B8)(void);extern int D_8009B0B0,D_8009B0A4,D_8009B0BC,D_8009B0D4,runtime_gp;
extern void func_800154E4(void),func_80041340(void),func_80014A5C(int),func_800136D4(void);
void func_8001306C(void)
{
 register void(**callback)(void) asm("$16");register int i asm("$17");func_800154E4();func_80041340();i=0;
 __asm__("lui $2, %%hi(D_800E9DB0)\naddiu %0,$2,%%lo(D_800E9DB0)":"=r"(callback));
 do{if(*callback)(*callback)();i++;callback++;}while(i<4);if(D_8009B0B8)D_8009B0B8();
 if(D_8009B0B0<D_8009B0A4||D_8009B0BC<D_8009B0D4)goto reset;runtime_gp--;if(runtime_gp<0)goto reset;goto done;
reset:runtime_gp=60;D_8009B0B0=D_8009B0A4;D_8009B0BC=D_8009B0D4;
done:func_80014A5C(0);func_800136D4();
}
