extern unsigned char D_8009B26C;
extern void func_8003BEB8(void), func_8016A080(void), func_8016A37C(void);
void func_8002D684(void) {
    unsigned char flags = D_8009B26C;
    if ((flags & 0x40) == 0) {
        D_8009B26C = flags | 0x40;
        func_8003BEB8();
        func_8016A080();
    }
    func_8016A37C();
}
