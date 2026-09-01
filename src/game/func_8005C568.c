#include "../types.h"

typedef struct { int words[6]; } Local;
extern void func_800803F4(Local *);
extern int func_80082324(int);
extern int func_80081FC0(Local *, int, int);
int func_8005C568(int first, int second)
{
    Local local;
    func_800803F4(&local);
    while (func_80082324(3) != 0) {}
    while (func_80081FC0(&local, first, second) != 0) {}
    return 0;
}
