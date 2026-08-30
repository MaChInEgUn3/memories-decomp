int func_80047C50(int value)
{
    register int result asm("$2") = value;
    value &= 0x8000;
    if (value)
        return result & 0xFFFF;
    return 0xFFFF;
}
