extern int func_80070870(int); extern int func_800708C4(int);
int func_80070920(int mode,int index)
{
    if(mode==1 && func_80070870(index)) return 1;
    if(mode==2 && func_800708C4(index)) return 1;
    return 0;
}
