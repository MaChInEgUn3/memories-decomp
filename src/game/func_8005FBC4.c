#include "../types.h"

typedef struct { short x, y, z, w; } Result;
void func_8005FBC4(int a, int b, int c, int d, Result *out, int scale)
{
    int x = (b - c) * scale;
    int y = (a + c - b * 2) * scale;
    int z = (b - a) * scale;
    out->w = a;
    out->x = x - a + d;
    out->y = y;
    out->z = z;
}
