typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

extern s32 D_800F5B98[];
extern s32 D_800F5BE8[];
extern s32 func_8007058C();
extern s32 func_800705AC();

void func_80070BB8(void)
{
    s32 first = func_8007058C();
    s32 second = func_8007058C();
    s32 third = func_8007058C();
    s32 offset = func_800705AC();
    s32 value = D_800F5B98[first];
    if (value <= D_800F5B98[second] &&
        D_800F5B98[third] <= value) {
        offset += D_800F5BE8[1];
        D_800F5BE8[2] = offset;
    }
}
