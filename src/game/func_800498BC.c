typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s16 func_80077240(s32);

s16 func_800498BC(s16 arg0)
{
    if (arg0 == 0) {
        return func_80077240(0);
    }
    return func_80077240(1);
}
