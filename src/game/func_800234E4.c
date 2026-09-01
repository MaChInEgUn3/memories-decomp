typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* D_800EFE48 "Slot" object record; see get_or_init_D_800EFE48_slot.c for the
   full layout. Only the fields this function touches are named here. */
struct Slot {
    char pad0[8];
    u16 f8;                  /* 0x8  -- status flags */
    char pad1[0x24 - 0xA];
    void (*f24)(void *self); /* 0x24 -- per-slot update callback */
    u16 f28;                 /* 0x28 -- looked up from D_80090800 */
    u16 f2A;                 /* 0x2A -- looked up from D_80090800 */
    char pad3[0x6A - 0x2C];
    u8 f6A;                  /* 0x6A */
    char pad4[0x70 - 0x6B];
};

struct Src {
    char pad0[4];
    struct Slot *f4;  /* 0x4 -- receives the spawned slot */
    char pad1[0xF - 8];
    s8 fF;            /* 0xF */
    s8 f10;           /* 0x10 */
    char pad2[0x17 - 0x11];
    u8 f17;            /* 0x17 */
};

/* Row of two u16 values selected by player index (D_8009B1D5) and a
   per-arg0 index; 0x50-byte stride per player, 4 bytes per row. */
struct Row {
    u16 f0;
    u16 f2;
};

extern struct Row D_80090800[];
extern u8 D_8009B1D5; /* current player index (0/1) */
extern s32 func_8004002C(void);
extern struct Slot *func_800400AC(s32 a0, s32 a1);
extern void *func_80040468(struct Slot *a0, s32 a1, s32 a2, s32 a3, s32 a5, s32 a6);
extern void func_80015D18(void *self);

/* Spawns a type-2 display object, lays it out via init_obj_id_pos_flags,
   copies its position pair from the D_80090800[player][idx] table (idx
   derived from arg0->f10*5+arg0->fF), sets status bit 0x28, installs
   func_80015D18 as its per-frame update callback, and stores the new
   slot pointer into arg0->f4. */
void func_800234E4(struct Src *arg0) {
    s32 idx;
    struct Slot *s1;
    struct Row *row;

    idx = arg0->f10 * 5 + arg0->fF;
    s1 = func_800400AC(func_8004002C(), 2);
    func_80040468(s1, 4, 3, arg0->f17 + D_8009B1D5 * 4, 0x1F, 0x100);

    {
        u8 *base = (u8 *)D_80090800;
        s32 off = idx * 4 + D_8009B1D5 * 0x50;
        row = (struct Row *)(base + off);
    }
    s1->f28 = row->f0;
    s1->f2A = row->f2;
    s1->f8 = s1->f8 | 0x28;
    s1->f24 = func_80015D18;
    arg0->f4 = s1;
}
