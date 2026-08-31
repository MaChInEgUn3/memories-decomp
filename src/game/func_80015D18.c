typedef unsigned short u16;
typedef struct {
    char p[0x28];
    u16 x, y;
    char p2C[4];
    u16 sx, sy;
} Object;
extern char D_800FE148[];
extern void func_800878D0(int);
extern void func_800878B0(int, int);
extern void func_800855D0(void *);

void func_80015D18(Object *object)
{
    func_800878D0(0x12C);
    func_800878B0(0xA0, 0x6C);
    func_800855D0(D_800FE148);
    __asm__ volatile(
        "lui $3, 0x1F80\n"
        "lhu $2, 40($16)\n"
        "ori $3, $3, 0x03E0\n"
        "sh $0, 2($3)\n"
        "sh $2, 0($3)\n"
        "lhu $2, 42($16)\n"
        "nop\n"
        "sh $2, 4($3)\n"
        "lwc2 $0, 0($3)\n"
        "lwc2 $1, 4($3)\n"
        "nop\n"
        "nop\n"
        ".word 0x4A180001\n"
        "addiu $2, $16, 48\n"
        "swc2 $14, 0($2)\n"
        : : : "$2", "$3"
    );
    object->sx -= 0x20;
    object->sy -= 0x1E;
    func_800878B0(0, 0);
}
