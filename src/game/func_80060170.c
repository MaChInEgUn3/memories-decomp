typedef struct { int first; int second; } Pair;
extern Pair D_800F5918[80];
void func_80060170(int key,int value)
{
    register Pair *entry asm("$6"); register int i asm("$7");
    register int *second asm("$3"); register int high asm("$2");
    asm("lui %0,%%hi(D_800F5918)\n\taddiu %1,%0,%%lo(D_800F5918)\n\taddu %2,$0,$0" : "=r"(high),"=r"(entry),"=r"(i));
    second=&entry->second;
    do { register int current asm("$2")=*second;
        if(current==key)return;
        if(current!=0)i++; else { if(entry->first==0){*second=key;entry->first=value;return;} i++; }
        second+=2; entry++;
    } while(i<80);
}
