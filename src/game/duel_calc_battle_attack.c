extern int Duel_CalcCardStats(void *);
extern int Duel_CalcGuardianStarBonus(void *, int);

int Duel_CalcBattleAttack(void *arg0, int arg1)
{
    int value = (unsigned short)Duel_CalcCardStats(arg0)
        + Duel_CalcGuardianStarBonus(arg0, arg1);

    if (value >= 10000) {
        value = 9999;
    }
    return value;
}
