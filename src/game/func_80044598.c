extern int func_8008E680(void *, int);

int func_80044598(int value, char *entry, int count)
{
    int i;
    for (i = 0; i < count; i++, entry += 40) {
        if (func_8008E680(entry, value) == 0)
            return i;
    }
    return -1;
}
