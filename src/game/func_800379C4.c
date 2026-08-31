typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern int func_80049120(void *);
void func_800379C4(u8 *object)
{
    if (func_80049120(object) != 1) {
        object[0x51] = 0;
    }
}
