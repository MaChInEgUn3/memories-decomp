extern unsigned char *D_8009B328;
extern void func_80039FD4(void);
void func_8003787C(unsigned char *object) {
    register unsigned char *state __asm__("$4");
    unsigned char flags = object[0x51];
    if ((flags & 0x80) == 0) object[0x51] = flags | 0x80;
    state = D_8009B328;
    if (state[0x33] == 0) {
        func_80039FD4();
        object[0x51] = 0;
    }
}
