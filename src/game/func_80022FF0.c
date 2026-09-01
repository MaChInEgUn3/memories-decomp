#include "../types.h"

typedef struct Entry { void *object; char p4[8]; } Entry;
typedef struct { char p0[4]; void *base; Entry *entries; } Parent;
extern void func_80022F98(Parent *, void *);

void func_80022FF0(Parent *argument, int flag)
{
    register Parent *parent asm("$19") = argument;
    register int clear asm("$20") = flag;
    register Entry *a asm("$17");
    register Entry *b asm("$16");
    register int i asm("$18");

    a = parent->entries;
    if (a != 0) {
        i = 0;
        b = (Entry *)((char *)a + 4);
        func_80022F98(parent, parent->base);
        parent->base = 0;
        do {
            func_80022F98(parent, a->object);
            func_80022F98(parent, b->object);
            if (clear) { a->object = 0; b->object = 0; }
            b++;
            i++;
            a++;
        } while (i < 5);
    }
}
