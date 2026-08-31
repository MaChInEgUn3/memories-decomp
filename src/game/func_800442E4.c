extern char D_800F2B00[];
extern char D_80010538[];
extern void *D_800F2AE0[];
extern short D_8009B44C;
extern int D_8009B430;
extern short D_8009B434;
extern int func_800440B4(int, int);
extern void func_8008F200(void *, void *, int, int);
extern void func_80043D48(void **);
extern void func_8008B330(int);

int func_800442E4(int value, int data, int global_data, int small, int extra)
{
    int result;
    if (func_800440B4(value, 4)) {
        func_8008F200(D_800F2B00, D_80010538, value, data);
        D_8009B44C = small;
        D_8009B430 = global_data;
        D_8009B434 = extra;
        func_80043D48(D_800F2AE0);
        func_8008B330(value);
        result = 1;
    } else {
        result = 0;
    }
    return result;
}
