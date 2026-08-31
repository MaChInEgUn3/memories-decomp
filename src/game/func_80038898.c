typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_8009B26C[];
extern u8 D_8009B363[];
void func_80038898(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    u8 value = *(*stream)++;
    D_8009B26C[0] = 5;
    D_8009B363[0] = value;
}
