typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Object {
    u16 x, y;
    u8 pad_04[0x16];
    u16 field_1A;
    u8 flags, count;
    u8 pad_1E[6];
    void (*callback)(struct Object *);
    u8 pad_28[0x44];
    u8 active;
} Object;
typedef struct { Object *object; u8 pad[0x10]; u32 state; u8 tail[4]; } Entry;
typedef struct { u8 pad[0x19]; u8 state; u8 tail[6]; } SideState;
extern volatile u8 D_8009B1D5;
extern Object *D_8009B1F0[2], *D_8009B17C;
extern u16 D_8009B220;
extern u8 D_800907D8[2][20];
extern Entry D_801A7AD8[];
extern SideState D_800E9FF0[2];
extern int func_80024E24(void);
extern Object *func_8002C604(int);
extern void func_8003FEE0(int), func_80025B28(Object *);
extern void *func_80042B40(int);

void func_80025F3C(void)
{
    Object *object;
    Entry *entry;
    int slot;
    register int side __asm__("$3");
    if (func_80024E24() == 0) {
        object = func_8002C604(0x15);
        side = D_8009B1D5 ^ 1;
        D_8009B17C = object;
        D_8009B1F0[side] = object;
        object->flags |= 0x20;
        object->x = 0xA0;
        object->y = 0x78;
        side = D_8009B1D5 ^ 1;
        object->field_1A = side;
        func_8003FEE0(0x23);
    } else if (!(D_8009B220 & 0x40)) {
        if (D_8009B17C->count != 0) {
            D_8009B220 |= 0x40;
            for (slot = 5; slot < 10; slot++) {
                entry = &D_801A7AD8[D_800907D8[D_8009B1D5][slot]];
                if ((entry->state & 0x90000000) == 0x90000000) {
                    register Object *current __asm__("$2");
                    current = entry->object;
                    current->callback = func_80025B28;
                    current->active = 1;
                }
            }
        }
    } else if (func_80042B40(1) == 0 && D_8009B17C->count >= 2) {
        D_800E9FF0[D_8009B1D5 ^ 1].state = 4;
        D_8009B220 = 0;
    }
}
