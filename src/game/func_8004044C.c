typedef struct {
    unsigned char pad0[8];
    unsigned short flags;
    unsigned char padA[0x5D];
    unsigned char field67;
    unsigned char field68;
    unsigned char field69;
} Object;

void func_8004044C(
    Object *object,
    unsigned char field67,
    unsigned char field68,
    unsigned char field69
)
{
    object->field67 = field67;
    object->field68 = field68;
    object->field69 = field69;
    object->flags &= 0xFFEF;
}
