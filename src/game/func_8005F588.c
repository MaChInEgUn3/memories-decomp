#include "../types.h"

extern signed char D_8009B07A;
extern unsigned char D_8009B07B;
extern unsigned char D_8009B07C;

void func_8005F588(int value)
{
    if (D_8009B07B != 1 || D_8009B07C != 1) {
        if (value == 0) {
            D_8009B07A = -1;
        } else {
            D_8009B07A = 0;
        }
    }
}
