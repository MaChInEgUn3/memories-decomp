#include "../types.h"

/* Same 32-entry lookahead window as scan_table2_80070870.c (offsets
   0x3E..0x7C from gAiScript_State, i.e. elements 31..62), cleared here. */
extern u16 gAiScript_State[];

void AiScript_ClearCards(void) {
    s32 i = 31;
    u16 *p = gAiScript_State;
    p += 31;
    do {
        p[31] = 0;
        i--;
        p--;
    } while (i >= 0);
}
