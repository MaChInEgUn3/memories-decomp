typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_8009B318;
extern u32 D_8009B0F4 __attribute__((section(".data")));
extern void func_800137E4(void);
extern void func_80044F58(s32);
extern void func_8005C388(s32, s32, s32, s32, s32);

void func_8003594C(s32 arg0)
{
    func_800137E4();
    func_80044F58(0xFF);
    D_8009B318 = 0x80;
    D_8009B0F4 |= 0x2000000;
    func_8005C388(arg0, 1, -1, 1, 0);
}
