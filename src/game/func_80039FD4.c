typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_80039F90(void *);
void func_80039FD4(u8 *object)
{
    *(s8 *)(object + 0x30) = -1;
    func_80039F90(object);
}
