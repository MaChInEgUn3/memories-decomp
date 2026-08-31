typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
int func_80039AAC(u8 *object)
{
    u8 flags = object[0x13];
    if ((flags & 0x80) == 0) {
        object[0x13] = flags | 0x80;
        return 0;
    }
    return 1;
}
