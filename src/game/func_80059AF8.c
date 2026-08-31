typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;
extern void func_80058938();

void func_80059AF8(
    s32 arg0, s32 arg1, Color4 arg2, Color4 arg3, s32 arg4)
{
    arg2.c3 = arg1 & 0x7F;
    func_80058938(arg0, 0, arg2, arg3, arg4, 0);
}
