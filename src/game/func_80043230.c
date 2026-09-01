#include "../types.h"

typedef struct {
    unsigned char pad0[0x30];
    short out_x;
    short out_y;
    short unused;
    short x;
    short y;
} Object;

extern int func_800866A0(int);

void func_80043230(Object *object, int target_x, int target_y, int phase)
{
    int dx = object->x - target_x;
    int dy = object->y - target_y;
    int factor;
    if (phase < 0) {
        factor = func_800866A0(phase + 0x400);
        object->out_x = object->x - (dx * factor) / 4096;
        object->out_y = object->y - (dy * factor) / 4096;
    } else {
        factor = -func_800866A0(phase);
        object->out_x = target_x - (dx * factor) / 4096;
        object->out_y = target_y - (dy * factor) / 4096;
    }
}
