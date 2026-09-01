#include "../types.h"

extern void func_80035AB8(int, int, int, int, int);
extern void func_80035AF0(int, int, int);
void func_80035BE4(int a, int b, int c, int d, int e, int f) {
    func_80035AB8(a, c, d, e, f);
    func_80035AF0(a, b, 0);
}
