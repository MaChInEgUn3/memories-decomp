#include "../types.h"

typedef struct {
    u8 pad_00[0xF];
    s8 x;
    s8 y;
} Object;

extern u8 D_8009B1D5;
extern u8 D_800907D8[];
extern void func_80023144(Object *, u8);

void func_8002348C(Object *object)
{
    u8 *table = D_800907D8;
    int index = object->y * 5 + object->x + D_8009B1D5 * 20;
    func_80023144(object, table[index]);
}
