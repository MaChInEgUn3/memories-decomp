typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_80036D3C(void *);
void func_80038388(u8 *object)
{
    *(u16 *)(object + 0x38) = func_80036D3C(object);
}
