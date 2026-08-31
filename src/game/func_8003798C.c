typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 D_8009B0F4[];
extern u32 D_8009B134[];
void func_8003798C(u8 *object)
{
    if (((D_8009B0F4[0] & 0x02000030) | D_8009B134[0]) == 0) {
        object[0x51] = 0;
    }
}
