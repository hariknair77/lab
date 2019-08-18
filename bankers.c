# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct{
    int pno,flag;
    int *allocated,*max,*need; 
}process;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

void disp(process p[],int np,int nr){
    int i,j;
    printf("Pno\tAlloacted\tMax\t\tNeed");
    for(i=0;i<np;i++){
        printf("\n%d\t",p[i].pno);
        for(j=0;j<nr;j++)
            printf("%d ",p[i].allocated[j]);
        printf("\t");    
        for(j=0;j<nr;j++)
            printf("%d ",p[i].max[j]);
        printf("\t");    
        for(j=0;j<nr;j++)
            printf("%d ",p[i].need[j]);
        printf("\t");    
    }       
}

int main(){
    int np,nr,i,j,temp,count,found;
    int *available,*safe_seq;
    srand(time(NULL));
    np = randint(1,10);
    nr = randint(4,5);
    available = (int *)malloc(nr*sizeof(int));
    safe_seq = (int *)malloc(np*sizeof(int));
    process *p = (process *)malloc(np*sizeof(process));
    for(i=0;i<nr;i++)
        available[i] = randint(1,10);
    for(i=0;i<np;i++){
        p[i].pno = i+1;
        p[i].flag = 0;
        p[i].allocated = (int *)malloc(nr*sizeof(int));
        p[i].max = (int *)malloc(nr*sizeof(int));
        p[i].need = (int *)malloc(nr*sizeof(int));
        for(j=0;j<nr;j++){
            p[i].allocated[j] = randint(1,10);
            temp = randint(1,5);
            p[i].max[j] = (p[i].allocated[j] + temp);
            p[i].need[j] = temp;
        }
    }   
    printf("\nAvailable");    
    for(i=0;i<nr;i++)
        printf("%4d",available[i]); 
    printf("\n");  

    disp(p,np,nr);

    count = 0;
    while (count<np){
        found = 0;
        for(i=0;i<np;i++){
            if(p[i].flag == 1)
                continue;
            for(j=0;j<nr;j++){
                if(p[i].need[j] > available[j]){
                    break;
                }
            }
            if(j == nr){
                found = 1;
                safe_seq[count] = p[i].pno;
                count++;
                p[i].flag = 1;
                for(int k=0;k<nr;k++)
                    available[k] += p[i].allocated[k];
            }                    
        }
        if(found == 0){
            printf("\nSystem is in unsafe state");
            break;
        }
    }

    printf("\nSafe Sequence");    
    for(i=0;i<np;i++)
        printf("%4d",safe_seq[i]);
    printf("\n");    
    return 0;
}
