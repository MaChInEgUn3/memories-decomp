int func_8004BAA0(const unsigned char *first, const unsigned char *second, int count)
{
    register int a asm("$3"), b asm("$2");
    if (count == 0) return -1;
    count--;
    goto test;
body:
    asm("lbu $3,0($4)\n\tlbu $2,0($5)" : "=r"(a), "=r"(b) : "r"(first), "r"(second));
    count--;
    if (a != b) goto done;
    first++;
    second++;
test:
    asm("" : "+r"(count));
    if (count != 0) goto body;
    asm("lbu $3,0($4)\n\tlbu $2,0($5)" : "=r"(a), "=r"(b) : "r"(first), "r"(second));
done:
    return a - b;
}
