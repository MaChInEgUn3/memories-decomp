extern unsigned char D_800F2C40[];
int func_80058EC0(int index)
{
    register unsigned char *base asm("$5") = D_800F2C40;
    register int offset asm("$3") = index * 0xE20;
    register unsigned char *entry asm("$2") = base + offset;
    register int selector asm("$4");
    register int result asm("$2");
    asm("" : "+r"(base), "+r"(offset), "+r"(entry));
    selector = entry[0xBF5];
    asm("nop\n\tsll %0,%1,4\n\tsubu %0,%0,%1\n\tsll %0,%0,2\n\tsubu %0,%0,%1\n\tsll %0,%0,1\n\taddu %0,%0,%2\n\taddu %0,%0,%3\n\tlhu %0,1988(%0)" : "=r"(result) : "r"(selector), "r"(offset), "r"(base));
    return result;
}
