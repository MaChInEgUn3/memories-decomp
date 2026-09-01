extern unsigned char *g_SDValue;
extern void func_80044DA0(void);
extern void func_80044DC0(int);

void func_80044D48(void)
{
    unsigned char *base;
    func_80044DA0();
    func_80044DC0(255);
    base = g_SDValue;
    *(unsigned char **)(base + 0x153C) = base + 0x53C;
    *(unsigned char **)(base + 0x1540) = base + 0x73C;
    *(unsigned char **)(base + 0x1544) = base + 0x93C;
    *(short *)(base + 0x512) = 0;
    *(unsigned char **)(base + 0x1548) = base + 0xB3C;
}
