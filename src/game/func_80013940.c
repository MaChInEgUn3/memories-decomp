typedef struct {
    unsigned char padding[0x10];
    volatile int field_10;
    int field_14;
    unsigned char padding_18[0xC];
    int field_24;
} Object;

extern int D_800E9EA8[];

void func_80013940(
    Object *object,
    int file_index,
    int sector_offset,
    int vertical
)
{
    object->field_10 = vertical;
    file_index &= 0xF;
    if (vertical < 0) {
        object->field_10 = -(vertical << 11);
    }

    if (sector_offset < 0) {
        object->field_14 = 0;
        object->field_24 = -sector_offset;
    } else {
        register volatile int *lbas = D_800E9EA8;

        object->field_14 = sector_offset << 11;
        object->field_24 = lbas[file_index] + sector_offset;
    }
}
