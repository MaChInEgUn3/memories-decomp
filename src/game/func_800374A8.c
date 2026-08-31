extern void func_800373C8(unsigned char *, int, int);
void func_800374A8(unsigned char *object) {
    unsigned char flags = object[0x51];
    if ((flags & 0x80) == 0) {
        object[0x51] = flags | 0x80;
        func_800373C8(object, 3, 0);
        object[0x51] = 0x82;
    }
}
