typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    u16 threshold;
    u8 pad6[0x3FE];
    u16 ids[4];
} SelectionState;

extern SelectionState *g_SDValue;
extern void func_80076ED0(s32, u32);

void func_80047A68(void)
{
    s32 i;
    u32 mask = 0x100000;
    u32 result = 0;
    u16 threshold = g_SDValue->threshold;

    for (i = 0; i < 4; i++) {
        if (g_SDValue->ids[i] >= threshold) {
            result |= mask;
        }
        mask <<= 1;
    }
    func_80076ED0(0, result);
}
