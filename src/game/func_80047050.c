typedef unsigned char u8;
typedef unsigned short u16;

extern u8 *D_8009B458;
extern u8 *g_SDValue;
extern void func_800495A4(void);
extern void func_80045F3C(void);
extern void func_80046A08(void);

void func_80047050(void)
{
    if (D_8009B458[0x509])
        func_800495A4();
    func_80045F3C();
    if (*(u16 *)(g_SDValue + 0x40) & 8)
        func_80046A08();
}
