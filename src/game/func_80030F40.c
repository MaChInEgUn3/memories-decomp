typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u16 D_8009B36A[];
extern u8 D_8009B368[];
extern void func_80024DC8(int, int, int, int);
void func_80030F40(void)
{
    D_8009B36A[0] = 0x71D0;
    D_8009B368[0] = 0;
    func_80024DC8(-1, 1, 0x8000, 0x8000);
}
