typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 value;
    u8 pad4[0x12];
    u16 flags;
    u8 pad18[4];
} Entry;

extern u8 D_8009B1D5;
extern Entry D_801A7B64[];
extern u16 func_800170C8(Entry *);

void func_8002C9B4(u32 *output, int selector)
{
    register Entry *entry __asm__("$16");
    register int base __asm__("$17");
    Entry *other;
    int index;

    if (selector < 0) {
        __asm__ volatile(
            "lui $2,%%hi(D_801A7B64)\n\t"
            "addiu %0,$2,%%lo(D_801A7B64)"
            : "=r"(entry));
        other = entry + 15;
        for (index = 0; index < 10; index++, entry++, other++) {
            if (entry->flags & 0x8000)
                *output++ = entry->value;
            if (other->flags & 0x8000)
                *output++ = other->value;
        }
        *output = 0;
        return;
    }

    base = D_8009B1D5 ? 5 : 20;
    __asm__ volatile(
        "sll $2,%1,3\n\t"
        "subu $2,$2,%1\n\t"
        "sll $2,$2,2\n\t"
        "lui $3,%%hi(D_801A7AD8)\n\t"
        "addiu $3,$3,%%lo(D_801A7AD8)\n\t"
        "addu %0,$2,$3"
        : "=r"(entry)
        : "r"(base)
        : "$2", "$3");
    if (selector >= 21) {
        for (index = 0; index < 5; index++, entry++) {
            if ((entry->flags & 0x8000) &&
                (u16)func_800170C8(entry) >= selector)
                *output++ = entry->value;
        }
    } else {
        for (index = 0; index < 5; index++, entry++) {
            if ((entry->flags & 0x8000) &&
                (selector < 0 || *(u8 *)(entry->value + 0x68) == selector))
                *output++ = entry->value;
        }
    }
    *output = 0;
}
