typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
int func_80032B38(u8 *object)
{
    u16 flags = *(u16 *)(object + 0x633E);
    if ((flags & 0x8000) == 0) {
        *(u16 *)(object + 0x633E) = flags | 0x8000;
        return 0;
    }
    return 1;
}
