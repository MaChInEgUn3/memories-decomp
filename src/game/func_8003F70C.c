#include "../types.h"

extern unsigned short D_8009B3FA;
extern unsigned char D_8009B3EF;
extern void func_8003F454(void);

int func_8003F70C(void)
{
    func_8003F454();
    if (D_8009B3FA != 0) {
        return 0;
    }
    return D_8009B3EF;
}
