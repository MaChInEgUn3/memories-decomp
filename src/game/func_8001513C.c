typedef struct Object {
    char pad_00[0x1C];
    int reset;
    void (*callback)(struct Object *, int);
    char pad_24[4];
    int timer;
    char pad_2C[0x14];
    int count;
} Object;

void func_8001513C(Object *object)
{
    object->timer -= 0x800;
    if (object->timer <= 0) {
        object->reset = 0;
        if (object->callback != 0) {
            int count = object->count++;
            object->callback(object, count);
        }
        object->timer = object->reset;
    }
}
