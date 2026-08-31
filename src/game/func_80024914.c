typedef struct {
    void *value;
    unsigned char pad4[0x12];
    unsigned short flags;
} Object;

extern void func_8004036C(void *);

void func_80024914(Object *object)
{
    object->flags &= 0x7FFF;
    if (object->value != 0) {
        func_8004036C(object->value);
        object->value = 0;
    }
}
