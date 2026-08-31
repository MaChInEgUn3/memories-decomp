extern unsigned char *D_8009B45C;
extern void (*D_8009B128)(void);
extern void func_8004544C(void);

void func_8004545C(void)
{
    register unsigned char *state asm("$3") = D_8009B45C;
    register int value asm("$2") = 1;

    state[0x1618] = value;
    D_8009B128 = func_8004544C;
}
