typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_801D0250[];
extern u16 D_801D0200[];
extern void func_8002CCE4();

void func_8002BF3C(void)
{
    u8 *p = D_801D0250;
    s32 i = 0;
    u16 *q;
    do {
        if (*p != 0)
            func_8002CCE4(i + 0x121);
        i++;
        p++;
    } while (i < 0x2D2);
    q = D_801D0200;
    i = 0;
    do {
        if (*q != 0)
            func_8002CCE4(*q + 0x120);
        i++;
        q++;
    } while (i < 0x28);
}
