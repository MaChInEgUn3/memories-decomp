#include "../types.h"

/* Same *g_SDValue struct/entry layout as func_80045114.c (arr[16], stride
   0x30, f0 at offset 0). */
struct Entry {
    u8 f0;
    u8 pad[0x30 - 1];
};

struct S8009B45C {
    char pad0[0x4C];
    s16 f4C;    /* entry count */
    char pad1[0x80 - 0x4E];
    struct Entry arr[16];
};

extern struct S8009B45C *g_SDValue;

/* Scans entries [1, count) for one carrying a space (0x20), the 0x11
   CD-track marker, or a '$' (0x24) in f0; returns 1 on the first hit. */
s32 func_80045484(void) {
    s32 i;

    for (i = 1; i < g_SDValue->f4C; i++) {
        s32 c = g_SDValue->arr[i].f0;
        if (c == 0x20) {
            goto found;
        }
        if (c < 0x21) {
            if (c == 0x11) {
                goto found;
            }
            continue;
        } else {
            if (c != 0x24) {
                continue;
            }
        }
    found:
        return 1;
    }
    return 0;
}
