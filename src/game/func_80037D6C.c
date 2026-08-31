typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern s32 D_8009B350;
void func_80037D6C(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    u8 *current = *stream;
    u8 value = current[0];
    *stream = current + 1;
    object[0x51] = value;
    D_8009B350 = 1;
}
