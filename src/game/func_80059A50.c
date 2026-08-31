typedef struct { int words[7]; } Params;
extern void func_80058A7C(int, int, Params *);
void func_80059A50(int a, int b, Params *params)
{
    Params copy;
    register int w0 asm("$3") = params->words[0];
    register int w1 asm("$7") = params->words[1];
    register int w2 asm("$8") = params->words[2];
    register int w3 asm("$9") = params->words[3];
    copy.words[0]=w0; copy.words[1]=w1; copy.words[2]=w2; copy.words[3]=w3;
    w0=params->words[4]; w1=params->words[5]; w2=params->words[6];
    copy.words[4]=w0; copy.words[5]=w1; copy.words[6]=w2;
    asm("" : : "m"(copy));
    func_80058A7C(a,b,&copy);
}
