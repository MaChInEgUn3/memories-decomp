typedef struct {
    unsigned char pad0[0x36];
    short field36;
    short field38;
    short field3A;
    unsigned char pad3C[0x26];
    unsigned char field62;
    unsigned char field63;
    unsigned char field64;
} Object;

void func_800429D8(Object *object)
{
    if (object != 0) {
        object->field36 = 0;
        object->field38 = 0;
        object->field3A = 0;
        object->field62 = 0x80;
        object->field63 = 0x80;
        object->field64 = 0x80;
    }
}
