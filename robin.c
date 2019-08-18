# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct {
    int pno,at,bt,wt,tt,rt;
}process;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

void disp(process p[],int n){
    int i;
    printf("Pno\tBurst\tWait\tTurn Around Time");
    for(i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t\t%d\n",p[i].pno,p[i].bt,p[i].wt,p[i].tt);
}

void calc_wt(process p[],int n,int q){
    int i,t=0,flag;
    float ttt,twt;
    ttt = 0;
    twt = 0;
    while(1){
        flag = 0;
        for(i=0;i<=n;i++){
            if(p[i].rt > 0){
                flag=1;
                if(p[i].rt > q){
                    t += q;
                    p[i].rt -= q;
                }
                else{ 
                    t += p[i].rt;
                    p[i].tt = t;
                    p[i].wt = t-p[i].bt;
                    p[i].rt = 0;
                    twt += p[i].wt;
                    ttt += p[i].tt;
                }
            }
        }
        if(flag==0)
        break;
    }
    printf("\nAverage waiting time = %f",twt/n);
    printf("\nAverage Turn around time time = %f\n",ttt/n);  
}

int main(){
    int n,i,q;
    srand(time(NULL));
    n = randint(1,10);
    q = randint(1,10);
    process *p = malloc(n*sizeof(process));
    for(i=0;i<n;i++){
        p[i].pno = i+1;
        p[i].bt  = randint(0,25);
        p[i].wt  = 0;
        p[i].tt  = 0;
        p[i].rt  = p[i].bt;
    }    
    calc_wt(p,n,q);
    printf("\nTime Quantum = %d\n",q);
    disp(p,n);
    return 0;
}