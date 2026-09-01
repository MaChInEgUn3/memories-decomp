#include "../types.h"

extern void func_80046294(void);
extern void func_80049010(void);
extern void func_80077FF0(int);

void SD_Init(void)
{
    func_80046294();
    func_80049010();
    func_80077FF0(0);
}
