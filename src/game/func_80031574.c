typedef unsigned short u16;

typedef struct {
    char pad0[0x40];
    u16 field40;
} Object;

extern int gDuel_adwCardStats[];
extern void *func_8004002C(void);
extern Object *func_800400AC(void *, int);
extern void func_80040510();
extern void func_80042918(Object *);
extern void func_800428EC(Object *, int);

void func_80031574(int index, int arg1, int arg2, int arg3, int arg4)
{
    register int table_index __asm__("$16") = index;
    register int x __asm__("$17") = arg1;
    register int y __asm__("$18") = arg2;
    register Object *object __asm__("$19");
    register int field18 __asm__("$20") = arg3;
    register int bits __asm__("$2");
    int kind;

    object = func_800400AC(func_8004002C(), 1);
    func_80040510(object, x, y, 0x10, 0x10, 0, 0xC8, 0xB, 0x260, 0xFC);
    __asm__ volatile(
        "lui $2,%%hi(gDuel_adwCardStats)\n\t"
        "addiu $2,$2,%%lo(gDuel_adwCardStats)\n\t"
        "addiu %1,%1,-1\n\t"
        "sll %1,%1,2\n\t"
        "addu %1,%1,$2\n\t"
        "lw %0,0(%1)\n\t"
        "nop"
        : "=r"(bits), "+r"(table_index));
    kind = (bits >> 26) & 0x1F;
    switch (kind) {
    case 0x14:
    case 0x17:
        object->field40 += 0x10;
        break;
    case 0x15:
        object->field40 += 0x20;
        break;
    case 0x16:
        object->field40 += 0x30;
        break;
    }
    func_80042918(object);
    func_800428EC(object, 10);
    __asm__ volatile(
        "lui $5,0xF7FF\n\t"
        "addu $2,%0,$0\n\t"
        "sw $0,0x44($2)\n\t"
        "sh %1,0x18($2)\n\t"
        "lw $3,0x50($sp)\n\t"
        "lw $4,4($2)\n\t"
        "ori $5,$5,0xFFFF\n\t"
        "sh $3,0x1A($2)\n\t"
        "lui $3,%%hi(func_800313E8)\n\t"
        "addiu $3,$3,%%lo(func_800313E8)\n\t"
        "sw $3,0x24($2)\n\t"
        "lhu $3,8($2)\n\t"
        "and $4,$4,$5\n\t"
        "sw $4,4($2)\n\t"
        "andi $3,$3,0xFFF7\n\t"
        "sh $3,8($2)"
        :
        : "r"(object), "r"(field18)
        : "$2", "$3", "$4", "$5", "memory");
    (void)arg4;
}
