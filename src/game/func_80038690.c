typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_80036D3C(void *);
extern void func_8003FF08(int);
void func_80038690(void *object)
{
    func_8003FF08((u16)func_80036D3C(object));
}
