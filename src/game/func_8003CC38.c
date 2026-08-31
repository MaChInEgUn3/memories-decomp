typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern u8 D_800EF668[];
extern u32 D_8009B3A8;

void func_8003CC38(void)
{
    u8 *p = D_800EF668;
    if (p[0] == 0 && (p[1] & 0xF) != 0)
        D_8009B3A8 |= ((p[2] << 8) | p[3]) ^ 0xFFFF;
    {
        u8 *q = D_800EF668;
        if (q[0x22] == 0 && (q[0x23] & 0xF) != 0)
            D_8009B3A8 |=
                ((((q[0x24] << 8) | q[0x25]) ^ 0xFFFF) << 16);
    }
}
