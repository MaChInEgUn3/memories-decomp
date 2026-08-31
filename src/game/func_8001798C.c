typedef unsigned char u8;
extern u8 D_8009B364[9];
extern void func_800171A8(void);
extern void func_80014E1C();
extern void func_800137E4(void);

void func_8001798C(void)
{
    int value = D_8009B364[0];
    int index = (((value * 15) * 4 - value) * 4 - value) + 0x16C6;
    func_80014E1C(0, 0, index, 0xEB, func_800171A8, 0, 0);
    func_800137E4();
}
