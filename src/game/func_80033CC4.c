typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 D_80090DD8[];
void func_80033CC4(u8 *object)
{
    register u8 *table asm("$2") = D_80090DD8;
    register u32 upper asm("$5") = object[0x2D47];
    register s32 lower asm("$3") = *(s8 *)(object + 0x2D46);
    upper <<= 4;
    lower <<= 1;
    lower += (s32)table;
    upper += lower;
    object[0x2D45] = ((u8 *)upper)[1] & 0xF;
}
