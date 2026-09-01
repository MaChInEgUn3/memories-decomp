#include "../types.h"

extern u8 gDuel_awPlayerDeck[];

void func_80021894(int arg0)
{
    int i;
    u8 *base = gDuel_awPlayerDeck;
    u8 *value = base + (arg0 + 0x4F);
    u16 *destination = (u16 *)(base + 0x5BC);
    u16 *entry;

    (*value)++;
    if (*value >= 0xFB) {
        *value = 0xFA;
    }
    i = 14;
    entry = (u16 *)(base + 0x5D8);
    do {
        entry[1] = entry[0];
        entry--;
        i--;
    } while (i >= 0);
    *destination = arg0;
}
