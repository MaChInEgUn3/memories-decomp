extern int func_8007058C(void);
extern int func_8008E870(const char *, ...);
extern const char D_80011908[];
extern const char D_80011918[];

void func_800736C4(void)
{
    int checkpoint = func_8007058C();

    func_8008E870(D_80011908);
    func_8008E870(D_80011918, checkpoint);
}
