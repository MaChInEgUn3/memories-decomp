#include "../types.h"

typedef struct {
    u8 pad_00[0x28];
    int field_28;
    u8 pad_2C[0x3E];
    u8 field_6A;
} Object;

typedef struct {
    u8 pad_00[0x28];
    int field_28;
    u8 pad_2C[0x44];
} Entry;

extern Entry D_800EFE48[];
extern void func_80015D18(Object *);

void func_80015DB8(Object *object)
{
    Entry *entry;

    entry = D_800EFE48 + object->field_6A;
    object->field_28 = entry->field_28;
    func_80015D18(object);
}
