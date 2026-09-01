#include "../types.h"

extern int func_8002CCA8(int);
extern void Library_UpdateCardUsedFlag(int);
int func_8002CD48(int value) {
    int result = func_8002CCA8(value);
    if (result == 0) Library_UpdateCardUsedFlag(value);
    return result;
}
