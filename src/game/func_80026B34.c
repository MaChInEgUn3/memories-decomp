typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
extern u16 D_8009B220;
extern s16 D_8009B1A8;
extern u8 D_80090AD4[];
extern void (*D_80090A5C[])(void);

int func_80026B34(void)
{
    u16 flags = D_8009B220;
    if (flags & 0x8000) {
        u8 *indices = D_80090AD4;
        void (**callbacks)(void);
        int index = indices[D_8009B1A8] * 2;
        if (flags & 0x4000) index++;
        callbacks = D_80090A5C;
        callbacks[index]();
    }
    return D_8009B220;
}
