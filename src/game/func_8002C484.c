int func_8002C484(int value) {
    int quotient = value / 10;
    return quotient * 178 + (value - quotient * 10) * 16 + 14;
}
