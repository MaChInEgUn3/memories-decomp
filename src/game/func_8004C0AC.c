typedef unsigned char u8;

extern unsigned int func_8004BB34(void *);
extern int func_8004BAE4(void *);

void func_8004C0AC(void *input)
{
    unsigned int i = 0;
    unsigned int count = func_8004BB34(input);
    do {
        i++;
        if ((u8)func_8004BAE4(input) == 247)
            break;
    } while (i < count);
}
