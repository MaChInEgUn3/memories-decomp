typedef unsigned char u8;

extern u8 *D_8009B45C;
extern void func_80076ED0(int, int);
extern void func_800773C4(void *);

void func_80047EC4(void)
{
    int count = 0;
    int total;
    do {
        func_80076ED0(0, 0x00F00000);
        func_800773C4(D_8009B45C + 0x15D8);
        total = D_8009B45C[0x15EF] + D_8009B45C[0x15ED] +
                D_8009B45C[0x15EE] + D_8009B45C[0x15EF];
        count++;
    } while (total != 0 && count < 24);
}
