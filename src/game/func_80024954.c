#include "../types.h"

typedef struct {
    void *value;
    unsigned char pad4[0x12];
    unsigned short flags;
} Object;

extern void func_80024914(Object *);

void func_80024954(Object *object)
{
    func_80024914(object);
    object->flags = 0;
}
