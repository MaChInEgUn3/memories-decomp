typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
int func_80036D3C(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    u8 *current = *stream;
    *stream = current + 2;
    return current[0] | (current[1] << 8);
}
