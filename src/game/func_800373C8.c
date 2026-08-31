extern unsigned char D_800EB288[];
void func_800373C8(unsigned char *object, int first, int second) {
    register unsigned int index __asm__("$2") = *(unsigned short *)(object + 0x5C);
    register unsigned int count __asm__("$4") = *(unsigned short *)(object + 0x5E);
    register unsigned char *entry __asm__("$3") = D_800EB288 + index * 28;
    if (count != 0) {
        entry += 0x15;
        while (count != 0) {
            if ((entry[-4] & 0x80) == 0) break;
            count--;
            entry[-2] = first;
            entry[0] = second;
            entry += 28;
        }
    }
}
