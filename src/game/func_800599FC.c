typedef struct { int words[8]; } Local;
extern void func_80058B4C(Local *, int, int, int, int, int, int, int);
void func_800599FC(int a, int b, int c, int d, int e, int f, int g)
{
    Local local;
    func_80058B4C(&local, a, b, c, d, e, f, g);
}
