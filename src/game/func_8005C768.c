extern void func_80089E20(void);
extern void func_8005CEF0(void);
extern void func_8005D378(void);
void *func_8005C768(unsigned int value)
{
    if ((value & 0xFFFF0000) != 0x03000000) goto default_case;
    value &= 0xFFFF;
    if (value == 0x2019) goto case_2019;
    if (value == 0x2119) goto case_2119;
    goto default_case;
case_2019:
    return func_8005CEF0;
case_2119:
    return func_8005D378;
default_case:
    return func_80089E20;
}
