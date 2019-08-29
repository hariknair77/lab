# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}
int cp;
int mode;
int comapre(const void *a,const void *b){
    int p = *(const int*)a;
    int q = *(const int*)b;   
    if(mode == 1){
        if(p > cp && q > cp)
            return p-q;
        else
            return q-p;
    }
    else{
        if(p < cp && q < cp)
            return q-p;
        else
            return p-q;
    }

}

int main(){
    printf("\nMode :");
    scanf("%d",&mode);
    cp = 50;
    int a[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = sizeof(a)/sizeof(a[0]);
    int tot = 0;
    for(int i=0;i<n;i++)
        printf("%d  ",a[i]);     
    printf("\n");
    qsort((void *)a,n,sizeof(int),comapre);
    tot += abs(cp - a[0]);
    for(int i=0;i<n;i++){
        
    }
    for(int i=0;i<n-1;i++){
        tot += abs(a[i]-cp);
        cp = a[i];
        if(a[i]>a[0]){

        }
        printf("(%d - %d) + ",a[i],a[i+1]);
    }
    printf("\nTotal = %d\n",tot);
    return 0;
}