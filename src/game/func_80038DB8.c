typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s32 func_80036D3C(u8 *);

void func_80038DB8(u8 *arg0)
{
    s32 c;
    s32 co;
    s32 no;
    s32 v;

    v = func_80036D3C(arg0);
    c = *(s8 *)(arg0 + 0x58);
    no = (c + 1) * 4;
    co = c * 4;
    *(s32 *)(arg0 + no) =
        (*(s32 *)(arg0 + co) & 0xFFFF0000) | (v & 0xFFFF);
    arg0[0x58]++;
}
