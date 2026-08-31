typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

extern u32 D_8009B10C;
extern u32 D_8009B0F4;
extern u32 D_8009B134;
extern u8 D_800E9E60[];
extern void func_80013998(u8 *, s32, u8 *, s32, s32, void *, s32, s32);

u8 *func_80014EEC(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5,
                  s32 arg6) {
    if (D_8009B10C == 0) {
        if (((D_8009B0F4 & 0x2000030) | D_8009B134) != 0) {
            return (u8 *)0;
        }
    } else {
        ((void (*)(void))D_8009B10C)();
    }
    func_80013998(D_800E9E60, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
    return D_800E9E60;
}
