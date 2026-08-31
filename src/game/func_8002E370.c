extern unsigned char D_800EB010[];
void func_8002E370(unsigned char *object) {
    register int i __asm__("$5") = 2;
    register signed char *base __asm__("$2") = (signed char *)D_800EB010;
    register signed char *entry __asm__("$3");
    __asm__ volatile("" : "+r"(base));
    entry = base + 0x98;
    for (; i >= 0; i--, entry -= 0x4C) {
        if (entry[0x30] >= 0) {
            *(unsigned short *)(object + 0x34) |= 2;
            return;
        }
    }
}
