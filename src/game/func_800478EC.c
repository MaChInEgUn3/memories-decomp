typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
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

extern struct S8009B45C_pad *D_8009B45C;
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
        if (D_8009B45C->f428[i] != 0) {
            if (D_8009B45C->f428[i] >= D_8009B45C->f424[i]) {
                D_8009B45C->f424[i] = 0;
            } else {
                D_8009B45C->f424[i] = D_8009B45C->f424[i] - D_8009B45C->f428[i];
            }
            if (D_8009B45C->f424[i] != 0) {
                func_80047864(i);
                goto tail;
            }
            D_8009B45C->f434 &= ~bit2;
            D_8009B45C->f428[i] = 0;
            func_80076ED0(0, mask);
            accum |= mask;
        }
    tail:
        timer = D_8009B45C->f42C[i];
        if (timer != 0) {
            timer -= 1;
            D_8009B45C->f42C[i] = timer;
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
