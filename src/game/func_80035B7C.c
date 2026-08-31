extern void func_80035CA8(int), func_80035DB8(int), func_8004036C(void *);
void func_80035B7C(unsigned char *object) {
    func_80035CA8(object[0x57]);
    func_80035DB8(object[0x57]);
    *(unsigned short *)(object + 0x34) = 0;
    func_8004036C(*(void **)(object + 0x30));
    func_8004036C(*(void **)(object + 0x2C));
    func_8004036C(*(void **)(object + 0x28));
    *(void **)(object + 0x30) = 0;
    *(void **)(object + 0x2C) = 0;
    *(void **)(object + 0x28) = 0;
}
