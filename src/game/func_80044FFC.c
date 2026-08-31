typedef struct {
    unsigned char command;
    unsigned char third;
    unsigned short second;
    unsigned char pad4[4];
    int first;
    unsigned char pad12[36];
} Request;

extern void func_80045BE8(Request *);

void func_80044FFC(int first, int second, int third)
{
    Request request;
    register int command asm("$2") = 0x29;

    asm("" : "+r"(command));
    first = (short)first;
    asm("" : "+r"(first));
    second = (unsigned char)second;
    request.command = command;
    request.second = second;
    request.third = third;
    request.first = first;
    func_80045BE8(&request);
}
