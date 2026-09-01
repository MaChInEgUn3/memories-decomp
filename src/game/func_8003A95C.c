#include "../types.h"

typedef struct {
    unsigned char pad[0x34];
    short field34;
    short field36;
} Object;

extern void func_8003A920(Object *, short, short);

void func_8003A95C(Object *object, int field34, int field36)
{
    object->field34 = field34;
    object->field36 = field36;
    func_8003A920(object, (short)field34, (short)field36);
}
