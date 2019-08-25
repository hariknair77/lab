# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct {
    int pno,at,bt,pr,wt,tt,flag;
}process;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}
void disp(process p[],int n){
    int i;
    printf("Pno\tAriaval\tBurst\tPriority\tWait\tTurn Around\tflag");
    for(i=0;i<n;i++)
        printf("\n%d\t%d\t%d\t%d\t\t%d\t%d\t\t%d\n",p[i].pno,p[i].at,p[i].bt,p[i].pr,p[i].wt,p[i].tt,p[i].flag);
}
void calc_wt(process p[],int n){
    int i,ct,finish_count,minpr,next_process, at_flag = 0;
    float ttt,twt = 0 ;
    ct = p[0].at + p[0].bt;
    p[0].tt = p[0].bt;
    ttt = p[0].bt;
    p[0].flag = 1; //First Process Complete
    finish_count = 1;
    // printf("\npno = %d ct = %d arival = %d waiting = %d ",p[0].pno,ct,p[0].at,p[0].wt);
    while(finish_count < n){
        at_flag = 0;
        minpr = 100;
        for(i=1;i<n;i++){
            if(p[i].flag == 1)
                continue;
            else if(p[i].at < ct){
                at_flag = 1;
                if(p[i].pr < minpr){
                    minpr = p[i].pr;
                    next_process = i;
                }
                    
            }
            else if(at_flag == 0){
                next_process = i;
                break;
            }        
        }

    if(at_flag == 1){
        p[next_process].wt = ct - p[next_process].at;
        ct += p[next_process].bt;
    }
    else
        ct = p[next_process].at + p[next_process].bt;
    // printf("\npno = %d ct = %d arival = %d waiting = %d ",p[next_process].pno,ct,p[next_process].at,p[next_process].wt);
    p[next_process].flag = 1;
    finish_count++;
    p[next_process].tt = p[next_process].wt + p[next_process].bt;    
    twt += p[next_process].wt;    
    ttt += ( p[next_process].wt + p[next_process].bt );    
    }
    printf("\nAverage waiting time = %f",twt/n);
    printf("\nAverage Turn around time time = %f\n",ttt/n);

}

int compare(const void *p,const void *q){
    int at1 = ((process *)p)->at;
    int at2 = ((process *)q)->at;
    int pr1 = ((process *)p)->pr;
    int pr2 = ((process *)q)->pr;
    if(at1 == at2)
        return pr1-pr2; //lower number highrt priorty
    else
        return at1-at2;        
}

int main(){
    int n,i;
    srand(time(NULL));
    n = randint(1,10);
    process *p = malloc(n*sizeof(process));
    for(i=0;i<n;i++){
        p[i].pno = i+1;
        p[i].bt  = randint(1,25);
        p[i].at  = randint(0,25);
        p[i].pr  = randint(1,10);
        p[i].flag = 0;
        p[i].wt  = 0;
        p[i].tt  = 0;
    }    
    disp(p,n);  
    qsort(p,n,sizeof(process),compare);  
    calc_wt(p,n);
    disp(p,n);
    return 0;
}