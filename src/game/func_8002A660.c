typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

extern s16 D_8009B146;
extern s16 D_8009B148;

void func_8002A660(u8 *arg0)
{
    s32 d = *(s16 *)(arg0 + 0xA) - D_8009B148;
    s32 h;

    D_8009B146 = 0;
    h = *(u16 *)(arg0 + 0xA);
    if (d < 0x40) {
        D_8009B148 = h - 0x40;
    }
    if (d >= 0xB0) {
        D_8009B148 = *(u16 *)(arg0 + 0xA) - 0xB0;
    }
}
