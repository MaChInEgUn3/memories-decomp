#include "../types.h"

extern int func_8007D3F0(int, int);

int File_Exists(int first, int second)
{
    register int result asm("$3") = func_8007D3F0(second, first);
    register int output asm("$2") = -1;

    if (result == 0) {
        goto negative;
    }
    if (result != output) {
        output = 0;
        goto done;
    }
negative:
    output = -1;
done:
    return output;
}
