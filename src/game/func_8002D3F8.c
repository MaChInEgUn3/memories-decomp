extern unsigned char D_8009B26C;
extern void func_8003B9BC(void), func_80015A00(void), func_80168FB4(void), func_8003FF34(void);
void func_8002D3F8(void) {
    unsigned char flags = D_8009B26C;
    if ((flags & 0x40) == 0) {
        D_8009B26C = flags | 0x40;
        func_8003B9BC();
        func_80015A00();
    }
    func_80168FB4();
    if ((D_8009B26C & 0x40) == 0) func_8003FF34();
}
