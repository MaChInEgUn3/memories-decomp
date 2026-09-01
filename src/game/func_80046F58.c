#include "../types.h"

extern void func_80047EC4(void);
extern void func_8004763C(void);
extern void SD_Init(void);
extern void func_80049640(void);
extern void func_80076D90(int);
extern void func_80075B60(void);

void func_80046F58(void)
{
    func_80047EC4();
    func_8004763C();
    SD_Init();
    func_80049640();
    func_80076D90(0);
    func_80075B60();
}
