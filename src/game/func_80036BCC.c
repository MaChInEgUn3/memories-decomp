extern unsigned char D_801D9174[];
unsigned char *func_80036BCC(unsigned int wanted) {
    register unsigned char *result __asm__("$6");
    register unsigned char *ids __asm__("$5");
    __asm__ volatile(
        "lui $2, %%hi(D_801D9174)\n\t"
        "addiu $6, $2, %%lo(D_801D9174)\n\t"
        "lui $2, %%hi(D_801D9174)\n\t"
        "addiu $5, $2, %%lo(D_801D9174)"
        : "=r"(result), "=r"(ids));
    for (;;) {
        unsigned int id = (ids[0] << 8) | ids[1];
        if (id == 0) return 0;
        if (id == wanted) return result;
        ids += 2;
        result += 0x1E;
    }
}
