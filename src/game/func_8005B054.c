#include "../types.h"

typedef struct { unsigned char r, g, b; } Color;
extern void func_8005ABA0(Color *, int, unsigned int, unsigned int, int);
int func_8005B054(int value, unsigned int a, unsigned int b)
{
    Color color;
    func_8005ABA0(&color, value, a & 0xFFFF, b & 0xFFFF, 31);
    return (color.r & 31) | ((color.g & 31) << 5) | ((color.b & 31) << 10);
}
