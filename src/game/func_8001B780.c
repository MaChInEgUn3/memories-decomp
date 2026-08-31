typedef signed char s8;

typedef struct {
    unsigned char pad0[0x30];
    short field30;
    short field32;
} Inner;

typedef struct {
    unsigned char pad0[4];
    Inner *inner;
    unsigned char pad8[6];
    s8 fieldE;
} Object;

void func_8001B780(Object *object)
{
    Inner *inner = object->inner;

    inner->field30 = object->fieldE * 60 + 14;
    inner->field32 = 194;
}
