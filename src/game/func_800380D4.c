typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
void func_800380D4(u8 *object)
{
    register u8 **stream asm("$3");
    register u8 *current asm("$2");
    register u32 value asm("$5");
    *(u16 *)(object + 0x38) = 0;
    stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    current = *stream;
    value = current[0];
    current++;
    *stream = current;
    *(u16 *)(object + 0x3A) += (s8)value;
}
