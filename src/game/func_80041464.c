typedef struct {
    unsigned char pad0[4];
    unsigned int flags;
    unsigned char pad8[0x48];
    unsigned char *current;
    unsigned char *base;
    unsigned short field58;
} Object;

int func_80041464(Object *object, const unsigned char *data)
{
    object->flags ^= 0x800000;
    object->field58 = 0;
    object->current = object->base + ((data[1] << 8) | data[0]);
    return 1;
}
