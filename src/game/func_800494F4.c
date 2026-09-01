#include "../types.h"

extern int *D_8009B458;
extern void func_80074E60(void);
extern void func_8004A6D8(void);
extern void func_80049434(void);

void func_800494F4(int *data)
{
    unsigned int i = 0;
    D_8009B458 = data;
    do {
        *data = 0;
        i++;
        data++;
    } while (i < 530);
    func_80074E60();
    func_8004A6D8();
    func_80049434();
}
