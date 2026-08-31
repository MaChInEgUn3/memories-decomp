extern unsigned char D_8009B2EB;
extern unsigned char D_8009B254[];
extern int func_8002892C(void);
void func_80030E30(void) {
    unsigned char flags = D_8009B2EB;
    if ((flags & 0x80) == 0) { D_8009B2EB = flags | 0x80; D_8009B254[0] = 3; }
    if (func_8002892C() == 0) D_8009B2EB = 0;
}
