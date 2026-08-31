typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_800EAF08[];
extern u8 D_8009B324;
extern u8 D_8009B325;
void func_80035CE4(void)
{
    register u8 *entry asm("$2") = D_800EAF08;
    register int remaining asm("$3") = 0xEF;
    do {
        *entry++ = 0;
    } while (--remaining >= 0);
    D_8009B324 = 0;
    D_8009B325 = 0;
}
