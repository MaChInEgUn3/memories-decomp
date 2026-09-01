#include "../types.h"

typedef struct { char p[0x22]; u8 flag; char p23[0x45]; u8 type; } Object;

int func_800181EC(Object *object)
{
    int value = 1;
    switch (object->type) {
    case 0x14: case 0x17: value = 2; break;
    case 0x15: value = 3; break;
    case 0x16: value = 4; break;
    }
    if (object->flag != 0) value |= 0x80;
    return value;
}
