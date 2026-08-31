typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u8 *D_8009B328;
void func_800378D8(u8 *object)
{
    u8 flags = object[0x51];
    if ((flags & 0x80) == 0) {
        object[0x51] = flags | 0x80;
    }
    if (D_8009B328[0x33] == 0) {
        object[0x51] = 0;
    }
}
