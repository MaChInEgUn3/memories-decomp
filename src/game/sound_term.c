#include "../types.h"
#include "sound.h"

extern void func_80049434(void);
extern void func_8004A6D8(void);
extern void func_8004B910(void);
extern void func_80075B60(void);

void func_80049640(void)
{
    s32 value;

    func_8004A6D8();
    value = D_8009B458->field_081C;
    if (value > 0) {
        if (value < 4)
            func_8004B910();
    }
    func_80049434();
}

void SD_Term(void)
{
    func_8004A6D8();
    func_80049434();
    func_80075B60();
}
