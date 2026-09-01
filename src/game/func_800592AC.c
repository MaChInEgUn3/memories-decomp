#include "../types.h"

typedef struct {
    s16 vx, vy, vz, pad;
} SVECTOR;

typedef struct {
    char pad0[0x20];
} MATRIX;

/* Same D_800F2C40[] slot array (stride 0xE20) as init_light_triplet_800f2c40.c;
   this reads a different sub-record at +0xD18, whose +0x44/+0x46/+0x48 fields
   hold camera-relative rotation offsets used to build an object's matrix. */
typedef struct {
    char pad0[0xD18];
    struct {
        char pad0[0x44];
        u16 f44;
        u16 f46;
        u16 f48;
    } *f0D18;
} Slot;

/* arg2's transform block: unk0 flag, a 0x20-byte MATRIX at +4, then the
   computed rotation angles at +0x44/+0x46/+0x48, and an id/handle at +0x4C. */
typedef struct {
    s32 f0;
    MATRIX f4;
    char pad24[0x44 - 0x24];
    s16 f44;
    s16 f46;
    s16 f48;
    char pad4A[0x4C - 0x4A];
    s32 f4C;
} Obj;

extern u8 D_800F2C40[16];
extern MATRIX *func_80087370(MATRIX *m0, MATRIX *m1);
extern MATRIX *func_800889C0(SVECTOR *r, MATRIX *m);
extern void func_80088E50(SVECTOR *r, MATRIX *m);
extern void *func_8008E3D0(void *p, s32 v, u32 n);
extern u16 D_8009B47A;
extern u16 D_8009B47C;

/* Builds arg2's rotation matrix from a camera-relative direction vector
   (derived from D_8009B47A/D_8009B47C) combined with the per-slot base
   angles at D_800F2C40[arg0]+0xD18, then stamps arg2's id field with arg1. */
void func_800592AC(s32 arg0, s32 arg1, Obj *arg2) {
    SVECTOR packed;
    SVECTOR raw;
    MATRIX sp20;
    Slot *slot;

    func_8008E3D0(&raw, 0, 8);
    raw.vy = (s16)(0x1000 - D_8009B47A);
    raw.vz = (s16)D_8009B47C;

    slot = (Slot *)(D_800F2C40 + arg0 * 0xE20);

    packed = raw;

    arg2->f0 = 0;
    arg2->f44 = (s16)(0x1000 - slot->f0D18->f44);
    arg2->f46 = (s16)(0x1000 - slot->f0D18->f46);
    arg2->f48 = (s16)(0x1000 - slot->f0D18->f48);

    func_800889C0((SVECTOR *)&arg2->f44, (MATRIX *)((u8 *)arg2 + 4));
    func_80088E50(&packed, &sp20);
    func_80087370((MATRIX *)((u8 *)arg2 + 4), &sp20);

    *(s32 *)((u8 *)arg2 + 0x20) = 0;
    *(s32 *)((u8 *)arg2 + 0x1C) = 0;
    *(s32 *)((u8 *)arg2 + 0x18) = 0;
    arg2->f4C = arg1;
}
