extern unsigned char D_801D0000[];
extern int func_8002C4DC(void);
int func_8002C518(int offset) {
    register unsigned char *entry __asm__("$2") = D_801D0000 + offset;
    int status = entry[0x24F] ? 1 : -1;
    __asm__ volatile("" : "+r"(status));
    if (status < 0) return func_8002C4DC();
    return 1;
}
