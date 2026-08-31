extern unsigned char D_8009B3C1;
extern unsigned char D_8009B3EB;
extern void func_8003E490(void);

void func_8003E7D4(void)
{
    if ((D_8009B3C1 & 0x80) == 0) {
        D_8009B3C1 |= 0x80;
        D_8009B3EB = 0;
    }
    func_8003E490();
}
