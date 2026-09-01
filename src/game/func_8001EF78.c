extern int Duel_CalcCardStats(void *);
extern int func_8001EE44(void *, int);

int func_8001EF78(void *arg0, int arg1)
{
    int value = (Duel_CalcCardStats(arg0) >> 16)
        + func_8001EE44(arg0, arg1);

    if (value >= 10000) {
        value = 9999;
    }
    return value;
}
