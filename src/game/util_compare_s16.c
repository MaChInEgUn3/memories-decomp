int Util_CompareS16(const short *left, const short *right)
{
    if (*left == *right) {
        return 0;
    }
    if (*left > *right) {
        return 1;
    }
    return -1;
}
