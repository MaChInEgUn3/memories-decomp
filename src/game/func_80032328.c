#include "../types.h"

extern void func_80032184(void);
extern void func_80014E1C(int, int, int, int, void *, int, int);
extern void func_800137E4(void);
void func_80032328(void) {
    func_80014E1C(0, 0, 0x2189, 0x4C, func_80032184, 0, 0);
    func_800137E4();
}
