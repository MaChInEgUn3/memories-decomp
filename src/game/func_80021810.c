typedef unsigned short u16;
extern char D_8017878C[];
extern int func_8008E590(void);

int func_80021810(int arg0)
{
    register int offset asm("$16");
    register u16 *entry asm("$16");
    int target;
    int total;
    int i;

    offset = arg0 * 1460;
    entry = (u16 *)(D_8017878C + offset);
    target = (func_8008E590() & 0x7FF) + 1;
    total = 0;
    i = 0;
    do {
        total += *entry;
        if (total >= target) return i + 1;
        i++;
        entry++;
    } while (i < 0x2D2);
    return 0;
}
