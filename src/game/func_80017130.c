typedef unsigned short u16;
typedef struct {
    u16 a, b, c, d, e, f, g, h;
    char rest[0x20];
} State;
extern State D_800F2848;
extern void func_800857C0(int);
extern void func_8001352C(void);

void func_80017130(void)
{
    State *s = &D_800F2848;
    int *words;

    s->a = 0x258;
    s->b = 0x400;
    s->c = 0x100;
    s->g = 0;
    *(int *)((char *)s + 0x28) = 0;
    *(int *)((char *)s + 0x2C) = 0;
    s->h = 0x12C;
    func_800857C0(0x12C);
    words = (int *)((char *)s + 0x10);
    words[3] = 0;
    s->d = 0;
    words[4] = 0;
    s->e = 0;
    words[5] = 0;
    s->f = 0;
    func_8001352C();
}
