typedef unsigned char u8;

extern u8 *D_8009B45C;
extern void func_8007CDC0(u8 *);

void func_80044F58(int value)
{
    u8 data[4];
    u8 *first;
    u8 *second;
    D_8009B45C[0x533] = 7;
    data[0] = value;
    data[3] = 0;
    if (D_8009B45C[0x48] == 0) {
        data[1] = 0;
        data[2] = value;
    } else {
        data[1] = value;
        data[2] = 0;
    }
    func_8007CDC0(data);
    first = D_8009B45C;
    first[0x49] = value;
    second = D_8009B45C;
    *(short *)(first + 0x510) = value;
    *(short *)(second + 0x512) = 0;
}
