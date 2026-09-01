extern int gFile_anLba[];
extern signed char gSD_bOutputType;
extern void func_80046990(int, int, int);
extern unsigned int func_8004703C(void);
extern void func_80012D4C(void);

void func_8003FE80(void)
{
    register volatile int *lbas = gFile_anLba;

    gSD_bOutputType = -1;
    func_80046990(lbas[4], lbas[5], lbas[6]);
    while (func_8004703C() & 8) {
        func_80012D4C();
    }
}
