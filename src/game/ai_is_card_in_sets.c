extern int Ai_IsCardInSet(int); extern int Ai_IsTypeInSet(int);
int Ai_IsCardInSets(int mode,int index)
{
    if(mode==1 && Ai_IsCardInSet(index)) return 1;
    if(mode==2 && Ai_IsTypeInSet(index)) return 1;
    return 0;
}
