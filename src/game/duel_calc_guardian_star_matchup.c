typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef short s16;
typedef int s32;

/* Called from func_8001EE44 (menu/list scroll helper). Given a current and a
   target grid index (col/row-style), works out whether the pair straddles a
   wrap boundary of the list (wraps at -7/+7 with widths 6 or 4) and returns
   a +/-500 "wrap jump" delta for the scroll animation, or 0 for a normal
   (non-wrapping) move. */
int Duel_CalcGuardianStarMatchup(int a0, int a1) {
    int v1;

    a0 -= 7;
    if (a0 >= 0) {
        a1 -= 7;
        if (a1 < 0) {
            return 0;
        }
        v1 = 4;
    } else {
        v1 = 6;
        a1 -= 1;
        a0 += v1;
        if (a1 >= v1) {
            return 0;
        }
    }

    a0 += 1;
    if (a0 >= v1) {
        a0 = 0;
    }
    if (a0 == a1) {
        return 500;
    }
    a0 -= 2;

    if (a0 < 0) {
        a0 += v1;
    }
    if (a0 == a1) {
        return -500;
    }
    return 0;
}
