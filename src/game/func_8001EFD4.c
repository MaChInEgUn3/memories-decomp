typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
extern u8 D_801A7AD8[];
extern s32 func_800170C8();
extern s32 func_8001EF78();
extern s32 func_8001EF1C();

s32 func_8001EFD4(u8 *left, u8 *right)
{
    u8 *a = D_801A7AD8 + left[106] * 28;
    u8 *b;
    s32 packed;
    s32 wanted;
    s32 actual;

    if (right == (u8 *)0)
        return func_800170C8(a) & 65535;
    b = D_801A7AD8 + right[106] * 28;
    packed = func_800170C8(b);
    wanted = packed & 65535;
    if (*(u16 *)(b + 22) & 2048)
        wanted = (u32)packed >> 16;
    if (*(u16 *)(a + 22) & 2048)
        actual = func_8001EF78(a, b);
    else
        actual = func_8001EF1C(a, b);
    if (actual != wanted)
        return actual - wanted;
    if ((*(u16 *)(a + 22) & 2048) || (*(u16 *)(b + 22) & 2048))
        return 0;
    return -1;
}
