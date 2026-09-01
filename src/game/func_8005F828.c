#include "../types.h"

extern s8 D_8009B07A;
extern u8 D_8009B07B;
extern u8 D_8009B07C;

extern void func_8005F91C(s32 flag, void *p1, void *p2, s32 arg3);

/* Walks two parallel arrays of 8-byte records (p1, p2), calling
   func_8005F91C(flag, p1, p2, arg3) once per step (up to count times),
   advancing each pointer by 8 bytes per step. Stops early once neither
   record's halfword field at +6 is still set (list exhausted). flag comes
   from D_8009B07A: incremented and turned into a >0 bool on the first call
   when the byte is non-negative, then forced to 1 for every later call in
   the same walk; skipped entirely (both the early return and the
   increment) if D_8009B07B/D_8009B07C both already read 1. */
void func_8005F828(s32 count, void *p1, void *p2, s32 arg3) {
    s8 raw172;
    s32 flag;

    if (D_8009B07B == 1 && D_8009B07C == D_8009B07B) {
        return;
    }

    raw172 = D_8009B07A;
    if (raw172 < 0) {
        flag = 0;
    } else {
        D_8009B07A = (u8)D_8009B07A + 1;
        flag = raw172 > 0;
    }

    if (count == 0) {
        return;
    }

    do {
        func_8005F91C(flag, p1, p2, arg3);

        if (p1 != 0) {
            p1 = (u8 *)p1 + 8;
        }
        if (p2 != 0) {
            p2 = (u8 *)p2 + 8;
        }

        if (p1 != 0 && *(s16 *)((u8 *)p1 + 6) != 0) {
            goto cont;
        }
        if (p2 == 0) {
            return;
        }
        if (*(s16 *)((u8 *)p2 + 6) == 0) {
            return;
        }
cont:
        if (count > 0) {
            count--;
        }
        flag = 1;
    } while (count != 0);
}
