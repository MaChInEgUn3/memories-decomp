int func_80024704(const short *left, const short *right)
{
    if (*left == *right) {
        return 0;
    }
    if (*left > *right) {
        return 1;
    }
    return -1;
}
