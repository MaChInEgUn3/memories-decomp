int func_80044544(char *entry, int count)
{
    int i;
    int total = 0;
    for (i = 0; i < count; i++, entry += 40) {
        int value = *(int *)(entry + 24);
        total += value / 8192;
        if (value % 8192)
            total++;
    }
    return 15 - total;
}
