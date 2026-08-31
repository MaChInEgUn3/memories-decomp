typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int field_00;
    int field_04;
    u8 pad_08[14];
    u16 field_16;
    u8 pad_18[4];
} Entry;

extern Entry D_801A7AD8[30];

void func_8001778C(void)
{
    u8 *entry = (u8 *)D_801A7AD8;
    int i = 0;
    u8 *field_16 = entry + 0x16;

    do {
        *(int *)entry = 0;
        *(int *)(field_16 - 0x12) = 0;
        *(u16 *)field_16 = 0;
        field_16 += sizeof(Entry);
        i++;
        entry += sizeof(Entry);
    } while (i < 30);
}
