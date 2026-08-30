typedef struct {
    int first;
    int second;
} Entry8;

extern Entry8 D_80091570[];

Entry8 *func_8005F1A4(int index)
{
    return &D_80091570[index];
}
