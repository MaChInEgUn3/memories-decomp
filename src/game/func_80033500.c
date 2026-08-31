typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
int func_80033500(u8 *object)
{
    s32 index = *(s16 *)(object + 0x2D3C) + *(s8 *)(object + 0x2D48);
    u8 *entry = object + index * 0x10;
    if (entry[0xD] == 0) {
        return 0;
    }
    return *(s16 *)(entry + 4);
}
