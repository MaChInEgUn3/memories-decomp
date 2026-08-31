typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef struct {
    char p0[8]; u16 flags; char pA[0x17]; u8 current;
    char p22[2]; void *callback; u8 target; char p29; s16 step;
    char p2C[0x40]; u8 active;
} Object;

void func_80019B2C(Object *object)
{
    int current = object->current + (u8)object->step;
    int difference;
    object->current = current;
    if (object->step >= 0) difference = object->target - current;
    else difference = current - object->target;
    if ((signed char)difference < 0) {
        register int target asm("$2") = object->target;
        object->active = 0;
        object->callback = 0;
        __asm__ volatile(
            "sb %0, 33(%1)\n"
            "andi %0, %0, 0xFF"
            : "+r"(target) : "r"(object) : "memory"
        );
        if (target == 0) object->flags &= ~4;
    }
}
