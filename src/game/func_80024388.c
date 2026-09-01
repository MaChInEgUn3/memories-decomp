typedef unsigned char u8;
typedef signed char s8;
extern s8 gDuel_bOpponentID[9], D_8009B238;
extern u8 D_8009B1D5;
extern void func_8003CDF8(void);
extern void func_80024200(void);
extern void func_8003CE48(void);

void func_80024388(void)
{
    int value = 0;
    if (gDuel_bOpponentID[0] < 0) {
        value = D_8009B1D5;
        if (D_8009B238 >= 0) value = D_8009B238;
    }
    if (value != 0) {
        func_8003CDF8(); func_80024200(); func_8003CE48();
    } else {
        func_80024200();
    }
}
