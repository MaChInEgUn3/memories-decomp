#include "../types.h"

extern u8 *D_8009B458;
extern void func_8004C8C8(void);
extern void func_8004C84C(void);
extern void func_8004AAFC(void);

void func_8004B9E0(void)
{
    if (D_8009B458[0x501])
        return;
    D_8009B458[0x501] = 1;
    if (D_8009B458[0x502]) {
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
        func_8004C8C8();
    }
    func_8004C84C();
    func_8004AAFC();
    D_8009B458[0x501] = 0;
}
