#include "../types.h"

extern int func_8008E590(void);
int Rand_GetInterval(int divisor) { return func_8008E590() % divisor; }
