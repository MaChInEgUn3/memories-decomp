extern void func_80012D4C(void);

void func_80012D84(int count)
{
    do {
        func_80012D4C();
    } while (--count != 0);
}
