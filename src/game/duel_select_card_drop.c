typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Picks a weighted-random index (1-based, 0 = none) out of a 722-entry
   u16 weight table selected by a0 from the gDuel_awSaPowCardDrops record array
   (1460-byte stride: 722 weights + 16 bytes trailing padding). Rolls a
   threshold in [1, 2048] and walks the weights accumulating a running sum
   until it reaches or passes the threshold. */
struct Rec {
    u16 weights[722];
    u8 pad[1460 - 722 * 2];
};

extern struct Rec gDuel_awSaPowCardDrops[];
extern s32 func_8008E590(void);

s32 Duel_SelectCardDrop(s32 a0) {
    struct Rec *r = &gDuel_awSaPowCardDrops[a0];
    s32 threshold = (func_8008E590() & 0x7FF) + 1;
    s32 sum = 0;
    s32 i;

    for (i = 0; i < 722; i++) {
        sum += r->weights[i];
        if (sum >= threshold) {
            return i + 1;
        }
    }
    return 0;
}
