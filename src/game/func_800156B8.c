typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_800E9EC8[];

void func_800156B8(s32 arg0)
{
    u8 *p = D_800E9EC8;
    s32 i;

    for (i = 0x1D; i >= 0; i--) {
        *(p + i + 0xA) = arg0;
    }
}
