#include "../types.h"

typedef struct {
    unsigned char bytes[0xE20];
} EntryE20;

extern EntryE20 D_800F39F0[];

EntryE20 *func_8005949C(int index)
{
    return &D_800F39F0[index];
}
