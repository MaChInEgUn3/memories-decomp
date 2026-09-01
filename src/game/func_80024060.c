#include "../types.h"

typedef struct {
    unsigned char pad0[0x19];
    unsigned char field19;
} Object;

extern void func_80023FBC(Object *);

int func_80024060(Object *object)
{
    func_80023FBC(object);
    return object->field19;
}
