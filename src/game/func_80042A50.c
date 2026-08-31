typedef struct {
    unsigned char pad0[0x34];
    short field34;
    unsigned char pad36[4];
    short field3A;
    unsigned char pad3C[0x28];
    unsigned char field64;
} Object;

void func_80042A50(Object *object)
{
    int value = (object->field34 << 8) | object->field64;

    value += object->field3A;
    object->field64 = value;
    object->field34 = value >> 8;
}
