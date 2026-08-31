typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Object {
    struct Object *field_00;
    u8 pad_04[0x13];
    u8 field_17;
    u8 pad_18[0xC];
    void (*field_24)(void);
    u16 field_28;
    u16 field_2A;
    u16 field_2C;
    u8 pad_2E[2];
    u16 field_30;
    u16 field_32;
    u8 pad_34[0x38];
    u8 field_6C;
} Object;

extern void func_80022EEC(void);

void func_80022F98(Object *parent, volatile Object *object)
{
    Object *base;
    int index;

    if (object != 0) {
        base = parent->field_00;
        object->field_28 = object->field_30 - base->field_30;
        object->field_2A = object->field_32 - base->field_32;
        index = parent->field_17;
        object->field_6C = 1;
        object->field_24 = func_80022EEC;
        object->field_2C = index;
    }
}
