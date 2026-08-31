typedef unsigned char u8;

extern u8 D_8009AF2A;
extern u8 D_8009AF2C;
extern u8 D_8009AF2D;
extern char D_80010074[];
extern char D_80010090[];
extern char D_800100A8[];
extern void func_800222F4(void);
extern void func_8007EF84();

void func_80022618(void)
{
    register char *text asm("$4");

    func_800222F4();
    func_8007EF84(D_80010074, D_8009AF2C, D_8009AF2D);
    if (D_8009AF2A != 0) {
        text = D_80010090;
    } else {
        text = D_800100A8;
    }
    func_8007EF84(text);
}
