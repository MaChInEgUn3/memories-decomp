typedef struct {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char padA[0x5D];
    unsigned char field67;
    unsigned char field68;
    unsigned char field69;
} Object;

void func_80040410(Object *object, unsigned char value)
{
    object->field69 = value;
    object->flags &= 0xFFEF;
}
