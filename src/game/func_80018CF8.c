typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct SomeState {
    u8 pad[0x1A];
    s8 arr1A[5];
};
struct R6 {
    s16 id;
    u8 b2;
    u8 pad3[3];
};
struct Blob {
    u8 pad0[0x4B9FC];
    struct R6 cards[1];
};
extern struct SomeState *D_8009B1C8;
extern struct Blob D_8015C424;

s32 func_80018CF8(void) {
    s16 buf[5];
    s32 i;
    s32 a3;

    for (i = 0; i < 5; i++) {
        buf[i] = D_8009B1C8->arr1A[i];
    }

    for (a3 = 0x11; a3 < 0x16; a3++) {
        for (i = 0; i < 5; i++) {
            s16 v1 = buf[i];
            if (v1 >= 0) {
                s16 v0 = D_8015C424.cards[v1].id;
                if (v0 == a3) {
                    buf[i] = -1;
                    goto found;
                }
            }
        }
        return 0;
    found:;
    }

    return 1;
}
