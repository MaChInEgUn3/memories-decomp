#include "../types.h"

/* Same 25-entry lookahead window as scan_table3_800708c4.c (offsets
   126..150 from D_800F5BE8), cleared here. */
extern u8 gAiScript_State[];

void AiScript_ClearTypes(void) {
    s32 i = 24;
    u8 *p = gAiScript_State;
    p += i;
    do {
        p[126] = 0;
        i--;
        p--;
    } while (i >= 0);
}
