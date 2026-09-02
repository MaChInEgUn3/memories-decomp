#include "../types.h"

//@ target 49934 8C
//@ sym D_800F2C40=0x800F2C40
// Per-index (stride 0xE20) table; this function seeds 3 records of
// {s32,s32,s32,u8,u8,u8} at +0xD70/+0xD80/+0xD90 -- looks like X/Y/Z offsets
// plus an intensity-byte triple for a 3-point light/particle rig.
struct Entry {
    char pad0[0xE20];
};

extern struct Entry D_800F2C40[];

void Model_InitLightTriplet(s32 a0) {
    u8 *base = (u8 *)&D_800F2C40[a0];

    *(s32 *)(base + 0xD70) = 3000;
    *(s32 *)(base + 0xD74) = 5000;
    *(s32 *)(base + 0xD78) = 2000;
    *(base + 0xD7C) = 128;
    *(base + 0xD7D) = 128;
    *(base + 0xD7E) = 128;

    *(s32 *)(base + 0xD80) = -3000;
    *(s32 *)(base + 0xD84) = 5000;
    *(s32 *)(base + 0xD88) = -2000;
    *(base + 0xD8C) = 128;
    *(base + 0xD8D) = 128;
    *(base + 0xD8E) = 128;

    *(s32 *)(base + 0xD90) = 0;
    *(s32 *)(base + 0xD94) = -5000;
    *(s32 *)(base + 0xD98) = 0;
    *(base + 0xD9C) = 64;
    *(base + 0xD9D) = 64;
    *(base + 0xD9E) = 64;
}
