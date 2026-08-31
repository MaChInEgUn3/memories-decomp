typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_80036D3C(void *);
void func_800383B0(u8 *object)
{
    object[0x60] = 0;
    object[0x61] = func_80036D3C(object);
}
