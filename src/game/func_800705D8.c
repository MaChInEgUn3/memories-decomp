typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;


extern u8 D_800F5BE8[], D_800EAE88[], D_800F5B98[];
extern void func_8008E360(void *, s32);
void func_800705D8(void *arg0) {
    func_8008E360(D_800F5BE8, 0xD4);
    func_8008E360(D_800EAE88, 0xC);
    func_8008E360(D_800F5B98, 0x50);
    if (arg0 == 0) D_800F5BE8[0] = 1;
    *(void **)(D_800F5BE8 + 4) = arg0;
    *(void **)(D_800F5BE8 + 8) = arg0;
}
