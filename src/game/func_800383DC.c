typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

struct Obj {
    u8 pad[0x58];
    u8 counter;
};
extern u16 D_801C0000[];
extern u16 D_801D5800[];
extern u16 D_801B0000[];
extern u16 D_8009B32E;

u32 *func_800383DC(struct Obj *a0) {
    struct Obj *a3 = a0;
    s32 a2 = D_8009B32E;
    u32 v1;
    u8 counter;
    s32 offset;
    u32 *slot;

    if (a2 > 0xCFFF) {
        v1 = ((u32)D_801C0000 & 0xFFFF0000) + D_801C0000[a2 - 0xD000];
    } else if (a2 > 0x7FFF) {
        v1 = ((u32)D_801D5800 & 0xFFFF0000) + D_801D5800[a2 - 0x8000];
    } else {
        if (a2 >= 0x500) {
            a2 -= 0x100;
        }
        v1 = ((u32)D_801B0000 & 0xFFFF0000) + D_801C0000[a2];
    }

    counter = a3->counter + 1;
    a3->counter = counter;
    offset = (s8)counter;
    slot = (u32 *)((u8 *)a3 + offset * 4);
    *slot = v1;
    return slot;
}
