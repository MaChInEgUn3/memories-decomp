typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

typedef struct { s32 w[12]; } Blk48;
extern u8 *D_8009B45C;

s32 func_80045BE8(Blk48 *src) {
    u8 *b1;
    u8 *b2;
    u8 *b3;
    s32 n1;
    s32 n2;
    s32 one;

    b1 = D_8009B45C;
    n1 = *(s16 *)(b1 + 0x4C);
    if (n1 >= 0x10) {
        goto full;
    }
    {
        u8 *d = b1 + n1 * 48;
        d[0x80] = *(u8 *)src;
    }

    b2 = D_8009B45C;
    n2 = *(s16 *)(b2 + 0x4C);
    {
        u8 *d = b2 + n2 * 48;
        *(Blk48 *)(d + 0x80) = *src;
    }

    b3 = D_8009B45C;
    one = 1;
    *(u16 *)(b3 + 0x4C) = *(u16 *)(b3 + 0x4C) + one;
    return one;
full:
    return 0;
}
