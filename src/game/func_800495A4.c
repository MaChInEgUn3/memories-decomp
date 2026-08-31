typedef unsigned char u8;

extern u8 *D_8009B458;
extern void func_8004B9E0(void);

void func_800495A4(void)
{
    if (D_8009B458[0x814])
        func_8004B9E0();
}
