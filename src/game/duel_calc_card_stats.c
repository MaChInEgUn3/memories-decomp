typedef signed short s16;
typedef struct { char p[0xE]; s16 a, b, c, d; } Object;

int Duel_CalcCardStats(Object *object)
{
    int low = object->a + object->c + object->d;
    int high;
    if (low < 0) low = 0;
    if (low >= 10000) low = 9999;
    high = object->b + object->c + object->d;
    if (high < 0) high = 0;
    if (high >= 10000) high = 9999;
    return (high << 16) | low;
}
