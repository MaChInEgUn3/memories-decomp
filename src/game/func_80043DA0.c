extern int func_80073880(void *);

int func_80043DA0(void **items, int stop)
{
    do {
        if (func_80073880(items[0]) == 1)
            return 0;
        if (func_80073880(items[1]) == 1)
            return 1;
        if (func_80073880(items[2]) == 1)
            return 2;
        if (func_80073880(items[3]) == 1)
            return 3;
    } while (stop == 0);
    return -1;
}
