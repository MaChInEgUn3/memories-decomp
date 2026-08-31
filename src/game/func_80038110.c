typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
void func_80038110(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    register u8 **slot asm("$3") = stream;
    register u8 *current asm("$2") = *slot;
    register u32 value asm("$5") = current[0];
    current++;
    *slot = current;
    *(u16 *)(object + 0x38) += value;
}
