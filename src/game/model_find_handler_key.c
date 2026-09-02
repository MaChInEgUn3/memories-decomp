#include "../types.h"

/* Same 80-entry table and layout as table_insert_800f5918.c. */
struct Entry {
    s32 val;    /* 0x0 */
    s32 key;    /* 0x4 */
};

extern struct Entry D_800F5918[80];

/* Sentinel value some caller passes for "no match possible"; short-circuits
   without touching the table. Address of a PSY-Q LIBHMD.LIB structure
   (GsU_00000000), used here only as a magic pointer value, not for its
   library contents. */
extern s32 func_80089E20[];

/* Reverse lookup: finds the entry whose val matches, returns its key (or -1
   if val is the sentinel, or if no entry matches after scanning all 80). */
s32 Model_FindHandlerKey(s32 val) {
    struct Entry *e = D_800F5918;
    s32 i;
    if (val == (s32) func_80089E20) {
        return -1;
    }
    for (i = 0; i < 80; i++, e++) {
        if (e->val == val) {
            return e->key;
        }
    }
    return -1;
}
