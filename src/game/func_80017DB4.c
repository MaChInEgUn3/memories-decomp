typedef unsigned char u8;
typedef signed char s8;
typedef struct { char p[4]; u8 field_04; } Child;
typedef struct {
    char p0[4]; Child *child; char p8[0xC]; unsigned int flags;
    char p18[0x4F]; u8 field_67; char p68[2]; u8 index;
} Object;
typedef struct { char p[0x1F]; s8 field_1F; } State;
typedef struct { char p[4]; Child *child; char p8[0xC]; unsigned int flags; char rest[4]; } Entry;
extern Entry D_801A7AD8[];
extern State *D_8009B1C8;

void func_80017DB4(Object *object)
{
    register int index asm("$2") = object->index;
    register int offset asm("$3");
    Entry *entry;
    offset = (index * 7) * 4;
    entry = (Entry *)((char *)D_801A7AD8 + offset);
    if ((entry->flags & 0xA0000000) == 0xA0000000 && D_8009B1C8->field_1F != 0) {
        object->field_67 = entry->child->field_04 + 1;
        if (D_8009B1C8->field_1F < 0) object->field_67 = 0xFF;
    }
}
