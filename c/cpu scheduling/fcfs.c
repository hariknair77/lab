# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct {
    int pno,at,bt,wt,tt;
}process;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

int compare(const void *p,const void *q){
    int a = ((process *)p)->at;
    int b = ((process *)q)->at;
    return a-b;
}

void disp(process p[],int n){
    int i;
    printf("Pno\tArrival\tBurst\tWait\tTurn Around Time");
    for(i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t%d\t%d\n",p[i].pno,p[i].at,p[i].bt,p[i].wt,p[i].tt);
}

void calc_wt(process p[],int n){
    int i,ct;
    float ttt,twt = 0 ;
    ct = p[0].at + p[0].bt;
    p[0].tt = p[0].bt;
    ttt = p[0].bt;
    for(i=1;i<n;i++){
        if(p[i].at < ct){
            p[i].wt = ct - p[i].at;
            ct += p[i].bt;
        }
        else
            ct = p[i].at + p[i].bt;
        p[i].tt = p[i].wt + p[i].bt;    
        twt += p[i].wt;    
        ttt += ( p[i].wt + p[i].bt );      
    }
    printf("\nAverage waiting time = %f",twt/n);
    printf("\nAverage Turn around time time = %f\n",ttt/n);
}

int main(){
    int n,i;
    srand(time(NULL));
    n = randint(1,10);
    process *p = malloc(n*sizeof(process));
    for(i=0;i<n;i++){
        p[i].pno = i+1;
        p[i].at  = randint(0,25);
        p[i].bt  = randint(0,25);
        p[i].wt  = 0;
        p[i].tt  = 0;
    }    
    disp(p,n);
    qsort(p,n,sizeof(process),compare);  
    calc_wt(p,n);
    disp(p,n);
    return 0;
}