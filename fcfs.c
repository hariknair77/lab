# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct {
    int pno,at,bt,wt,tt;
}process;

int randint(int lower,int upper){
    srand(time(NULL));
    return rand()%(upper-lower+1)+lower;
}

void sort(process a[],int n){
    int i,j;
    process temp;
    for ( i = 0; i < n-1; i++)
        for( j = 0; j < n-1-i; j++)
            if ( a[j].at > a[j+1].at){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }   
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
    n = randint(1,10);
    process *p = malloc(n*sizeof(process));
    for(i=0;i<n;i++){
        p[i].pno = i+1;
        p[i].at  = randint(0,30);
        p[i].bt  = randint(0,30);
        p[i].wt  = 0;
        p[i].tt  = 0;
    }    
    disp(p,n);
    sort(p,n);    
    calc_wt(p,n);
    disp(p,n);
    return 0;
}