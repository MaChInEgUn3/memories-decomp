extern char gDuel_awPlayerShuffledDeck[];
extern void func_800243F4(void *, void *, void *);

void func_800245A0(void *arg0, void *arg1)
{
    char *base = gDuel_awPlayerShuffledDeck;

    func_800243F4(arg0, base, base - 0x54);
    func_800243F4(arg1, base + 0x50, base - 0x2C);
}
