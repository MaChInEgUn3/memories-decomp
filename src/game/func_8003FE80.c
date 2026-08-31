extern int D_800E9EA8[];
extern signed char D_8009B408;
extern void func_80046990(int, int, int);
extern unsigned int func_8004703C(void);
extern void func_80012D4C(void);

void func_8003FE80(void)
{
    register volatile int *lbas = D_800E9EA8;

    D_8009B408 = -1;
    func_80046990(lbas[4], lbas[5], lbas[6]);
    while (func_8004703C() & 8) {
        func_80012D4C();
    }
}
