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

extern void *D_8009B458;

void func_8004C5C8(u8 *p) {
    switch (*(u16 *)(D_8009B458 + 0x7FC)) {
    case 0x30:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) * 10;
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0x60:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) * 5;
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0xC0:
    case 0xF0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 1;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 1;
        return;
    case 0x120:
    case 0x168:
        *(u32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) / 3;
        return;
    case 0x180:
    case 0x1E0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 3;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 2;
        return;
    case 0x300:
    case 0x3C0:
        *(s32 *)(p + 0x1C) = *(s32 *)(p + 0x1C) + *(u16 *)(p + 0x18);
        *(s16 *)(p + 0x18) = *(u16 *)(p + 0x1C) & 7;
        *(s32 *)(p + 0x1C) = *(u32 *)(p + 0x1C) >> 3;
        return;
    default:
        return;
    }
}
