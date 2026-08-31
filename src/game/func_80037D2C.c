typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u16 D_8009B33A;
extern s32 D_8009B350;
void func_80037D2C(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    register s32 temporary asm("$2");
    register u32 combined asm("$3");
    register u32 value asm("$5");
    register u8 **slot asm("$4");
    temporary = *(s8 *)(object + 0x58);
    combined = D_8009B33A;
    asm("" : "+r"(temporary), "+r"(combined));
    slot = &((u8 **)object)[temporary];
    asm("" : "+r"(slot), "+r"(combined));
    combined -= 0xF0;
    temporary = (s32)*slot;
    combined <<= 8;
    value = *(u8 *)temporary;
    temporary++;
    *slot = (u8 *)temporary;
    temporary = -1;
    value |= combined;
    D_8009B33A = value;
    asm("" : "+r"(temporary) : : "memory");
    D_8009B350 = temporary;
}
