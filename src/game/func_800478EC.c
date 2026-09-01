#include "../types.h"

typedef float f32;
typedef double f64;
typedef char M2C_UNK;
typedef struct { s32 words[9]; } Mtx32;
typedef u8 State;
typedef u8 Record;
typedef u8 Pair;
typedef u8 Controller;
typedef u8 Entry;
typedef u8 Rec;
typedef u8 Block;
typedef struct { u32 words[2]; } Blk8;

struct S8009B45C_pad {
    u8 pad[0x424];
    u8 f424[4];
    u8 f428[4];
    u16 f42C[4];
    u8 f434;
};

extern struct S8009B45C_pad *g_SDValue;
extern s32 func_80047864();
extern s32 func_80076ED0();
extern s32 func_80077090();

void func_800478EC(void) {
    s32 mask;
    s32 bit2;
    s32 accum;
    s32 i;
    s32 v0;
    u16 timer;

    mask = 0x100000;
    bit2 = 1;
    accum = 0;
    for (i = 0; i < 4; i++) {
        if (g_SDValue->f428[i] != 0) {
            if (g_SDValue->f428[i] >= g_SDValue->f424[i]) {
                g_SDValue->f424[i] = 0;
            } else {
                g_SDValue->f424[i] = g_SDValue->f424[i] - g_SDValue->f428[i];
            }
            if (g_SDValue->f424[i] != 0) {
                func_80047864(i);
                goto tail;
            }
            g_SDValue->f434 &= ~bit2;
            g_SDValue->f428[i] = 0;
            func_80076ED0(0, mask);
            accum |= mask;
        }
    tail:
        timer = g_SDValue->f42C[i];
        if (timer != 0) {
            timer -= 1;
            g_SDValue->f42C[i] = timer;
            if (timer == 0) {
                v0 = func_80077090(mask);
                if (v0 != 0) {
                    func_80076ED0(0, mask);
                    accum |= mask;
                }
            }
        }
        v0 = func_80077090(mask);
        if (v0 == 3 && !(accum & mask)) {
            func_80076ED0(0, mask);
            accum |= mask;
        }
        bit2 <<= 1;
        mask <<= 1;
    }
    if (accum != 0) {
        func_80076ED0(0, accum);
    }
}
