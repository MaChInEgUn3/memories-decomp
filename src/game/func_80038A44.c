typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern u8 D_8009B355;
extern s32 func_80036D3C(u8 *);

void func_80038A44(u8 *arg0)
{
    s32 o = *(s8 *)(arg0 + 0x58) * 4;
    s32 v;

    *(s32 *)(arg0 + o) += D_8009B355 * 2;
    v = func_80036D3C(arg0);
    o = *(s8 *)(arg0 + 0x58) * 4;
    *(s32 *)(arg0 + o) =
        (*(s32 *)(arg0 + o) & 0xFFFF0000) | (v & 0xFFFF);
}
