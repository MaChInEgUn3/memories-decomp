typedef struct { void *pointer; short value; unsigned char pad[14]; } Entry;
extern void func_8004036C(void *);
void func_8002E00C(Entry *entries) {
    int i;
    *(short *)((unsigned char *)entries + 0x3C) = -1;
    for (i = 0; i < 3; i++, entries++) {
        func_8004036C(entries->pointer);
        entries->pointer = 0;
        entries->value = 0;
    }
}
