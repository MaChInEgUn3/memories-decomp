typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_80038024(void *, int);
void func_80038094(u8 *object)
{
    u8 **stream = &((u8 **)object)[*(s8 *)(object + 0x58)];
    func_80038024(object, *(*stream)++);
}
