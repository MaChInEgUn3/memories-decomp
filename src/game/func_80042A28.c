typedef struct {
    unsigned char pad0[0x32];
    short field32;
    unsigned char pad34[4];
    short field38;
    unsigned char pad3A[0x29];
    unsigned char field63;
} Object;

void func_80042A28(Object *object)
{
    int value = (object->field32 << 8) | object->field63;

    value += object->field38;
    object->field63 = value;
    object->field32 = value >> 8;
}
