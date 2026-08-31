typedef unsigned char u8;

extern int D_800E9E90[3];
extern unsigned int D_8009B0F4;
extern int func_8007E710(int);

void func_80014390(u8 arg0, int arg1)
{
    int value;
    int *destination;

    if (arg0 == 2) {
        destination = D_800E9E90;
        value = func_8007E710(arg1);
        if (value > 0) {
            *destination = value;
        }
        D_8009B0F4 &= ~0x800;
    }
}
