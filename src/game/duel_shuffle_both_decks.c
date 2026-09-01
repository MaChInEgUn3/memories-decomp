#include "../types.h"

extern char gDuel_awPlayerShuffledDeck[];
extern void Duel_ShuffleDeck(void *, void *, void *);

void Duel_ShuffleBothDecks(void *arg0, void *arg1)
{
    char *base = gDuel_awPlayerShuffledDeck;

    Duel_ShuffleDeck(arg0, base, base - 0x54);
    Duel_ShuffleDeck(arg1, base + 0x50, base - 0x2C);
}
