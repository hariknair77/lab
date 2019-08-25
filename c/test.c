# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}
int mode;
int comapre(const void *a,const void *b){
    int p = *(const int*)a;
    int q = *(const int*)b;   
    if(mode == 1)
        return p-q;
    else
        return q-p;
}

int main(){
    printf("\nMode : ");
    scanf("%d",&mode);
    int a[10];
    for(int i=0;i<10;i++)
        a[i] = randint(1,20);
    for(int i=0;i<10;i++)
        printf("%4d",a[i]);     
    printf("\n");
    qsort((void *)a,10,sizeof(int),comapre);
    for(int i=0;i<10;i++)
        printf("%4d",a[i]);
    return 0;
}