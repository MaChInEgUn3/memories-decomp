#include "../types.h"

/* Same D_8009B458_c stream-buffer struct family as clear_8009b458_4A4_if_set.c
   / reset_8009b458_idle_state.c. sub.f0 is the same discriminant as f4A4;
   sub.f10/f14 (absolute offsets 0x4B4/0x4B8) are a threshold and a base
   offset for the pending-transfer window, and f818 is the running byte
   count consumed from it. */
struct SubRec {
    s16 f0;
    char pad[0x10 - 2];
    s32 f10;
    s32 f14;
};

struct S8009B458 {
    char pad0[0x4A4];
    struct SubRec sub;
    char pad1[0x818 - 0x4A4 - 0x18];
    u32 f818;
};

extern struct S8009B458 *D_8009B458;
extern void func_800771B0(void *a0);
extern s32 func_80077150(void *a0, s32 a1);

/* Validates the caller's state token against the pending transfer's
   discriminant, clamps the requested byte count to what remains in the
   window, forwards it to SpuRead, and advances the consumed-byte
   counter. Returns the state token once the window fills, -2 while more
   remains, or -1 on a state mismatch or short transfer. */
s32 func_800497E0(void *rec, s32 count, s32 state) {
    struct S8009B458 *v1 = D_8009B458;
    struct SubRec *s1;
    s32 result;

    if (v1->sub.f0 != (s16)state) {
        return -1;
    }

    s1 = &v1->sub;
    func_800771B0((void *)(s1->f14 + v1->f818));

    {
        s32 remaining = s1->f10 - D_8009B458->f818;
        if ((u32)remaining < (u32)count) {
            count = remaining;
        }
    }

    result = func_80077150(rec, count);
    if (result != count) {
        return -1;
    }

    {
        u32 total = D_8009B458->f818 + count;
        D_8009B458->f818 = total;
        if (total >= (u32)s1->f10) {
            return (s16)state;
        }
    }

    return -2;
}
