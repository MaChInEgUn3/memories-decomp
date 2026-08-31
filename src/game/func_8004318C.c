typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 func_80086770();

void func_8004318C(u8 *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    s32 x = (*(s16 *)(arg0 + 0x36) + arg1) >> 1;
    s32 y = (*(s16 *)(arg0 + 0x38) + arg2) >> 1;
    s32 scale = func_80086770(arg3);
    s32 scale2 = scale;
    *(u16 *)(arg0 + 0x30) =
        x + (*(s16 *)(arg0 + 0x36) - x) * scale / 4096;
    *(u16 *)(arg0 + 0x32) =
        y + (*(s16 *)(arg0 + 0x38) - y) * scale2 / 4096;
}
