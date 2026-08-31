extern signed short D_8009B322;
extern int func_80036D3C(unsigned char *);
void func_800379F8(unsigned char *object) {
    unsigned char flags = object[0x51];
    if ((flags & 0x80) == 0) {
        object[0x51] = flags | 0x80;
        D_8009B322 = func_80036D3C(object);
    }
    D_8009B322--;
    if (D_8009B322 == 0) object[0x51] = 0;
}
