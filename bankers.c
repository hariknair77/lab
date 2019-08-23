# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef struct{
    int pno,flag,order;
    int *allocated,*max,*need,*avail; 
}process;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

void disp(process p[],int n,int nr,int seq[],int np){
    int i,j;
    if(n != np)
        for(i=0;i<np;i++)
            seq[i] = i+1;
    printf("Pno\tAlloacted\tMax\t\tNeed\t\tAvailable");
    for(i=0;i<np;i++){
        printf("\n%d\t",p[seq[i]-1].pno);
        for(j=0;j<nr;j++)
            printf("%d ",p[seq[i]-1].allocated[j]);
        printf("\t");    
        for(j=0;j<nr;j++)
            printf("%d ",p[seq[i]-1].max[j]);
        printf("\t");    
        for(j=0;j<nr;j++)
            printf("%d ",p[seq[i]-1].need[j]);
        printf("\t");    
        for(j=0;j<nr;j++)
            printf("%d ",p[seq[i]-1].avail[j]);
        printf("\t");  
    }       
    printf("\n");
}

int safe(process p[],int available [],int np,int nr){
    int safe_seq[np],count,found,i,j;
    // safe_seq = (int *)malloc(np*sizeof(int));
    printf("\nAvailable");    
    for(i=0;i<nr;i++)
        printf("%4d",available[i]); 
    printf("\n*******************************\n"); 
    
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
                p[i].order = p[i].pno;
                count++;
                p[i].flag = 1;
                for(int k=0;k<nr;k++){
                    available[k] += p[i].allocated[k];
                    p[i].avail[k] = available[k];
                }    
            }                        
        }
        if(found == 0){
            printf("System is in unsafe state\n*******************************\n");
            disp(p,count,nr,safe_seq,np);
            return 0;
        }
    }
    disp(p,count,nr,safe_seq,np);  
    printf("\nSafe Sequence < ");    
        for(i=0;i<np;i++)
            printf("p%d  ",safe_seq[i]);
        printf(">\n\n"); 
    return 1;         
}
void req(process p[],int avail[],int np,int nr){
    int pnum,request[nr],i;
    char ch,mode;
    scanf("%c",&ch);
    printf("\nRandom (y/n)?:");
    scanf("%c",&mode);
    if(mode == 'y'){
        pnum = randint(1,np);
        for(i=0;i<nr;i++)
            request[i] = randint(1,10);
    }
    else{
        printf("\nEnter process number : ");
        scanf("%d",&pnum);
        printf("\nEnter resource request : ");
        for(i=0;i<nr;i++)
            scanf("%d",&request[i]);
    }
    printf("\nPno = %d",pnum);
    printf("\nRequest\tNeed\tAvailable\n");
    for(i=0;i<nr;i++)
        printf("%d\t%d\t%d\n",request[i],p[pnum-1].need[i],avail[i]);
    for(i=0;i<nr;i++)
        if(request[i]>p[pnum-1].need[i]){
            printf("\nRequst exceed the maximum claim\n");
            return;
        }
    for(i=0;i<nr;i++)
        if(request[i] > avail[i]){
            printf("\nResource not available\n");
            return;
        }
    for(i=0;i<nr;i++){
        avail[i] -= request[i];
        p[pnum-1].allocated[i] += request[i];
        p[pnum-1].need[i] -= request[i];
    }
    for(i=0;i<np;i++){
        p[i].flag = 0;
        for(int j=0;j<nr;j++)
            p[i].avail[j] = 0;
    }
        
    // safe(p,avail,np,nr);
    if(safe(p,avail,np,nr)){
        printf("\nAddtional resorse request(y/n)?:");
        getchar();
        scanf("%c",&ch);
        (ch == 'y')?req(p,avail,np,nr):printf("\nBye\n");
    }

}

int main(){
    int np,nr,i,j,temp;
    char ch;
    srand(time(NULL));
    np = randint(1,10);
    nr = randint(4,5);
    int work[nr],available[nr];
    process p[np];
    // available = (int *)malloc(nr*sizeof(int));
    // process *p = (process *)malloc(np*sizeof(process));
    for(i=0;i<nr;i++){
        available[i] = randint(1,10);
        work[i] = available[i];
    }
    for(i=0;i<np;i++){
        p[i].pno = i+1;
        p[i].flag = 0;
        p[i].allocated = (int *)malloc(nr*sizeof(int));
        p[i].max = (int *)malloc(nr*sizeof(int));
        p[i].need = (int *)malloc(nr*sizeof(int));
        p[i].avail = (int *)malloc(nr*sizeof(int));
        for(j=0;j<nr;j++){
            p[i].allocated[j] = randint(1,10);
            temp = randint(1,5);
            p[i].max[j] = (p[i].allocated[j] + temp);
            p[i].need[j] = temp;
            p[i].avail[j] = available[j];
        }
    }   
    if(safe(p,available,np,nr)){
        printf("\nAddtional resorse request(y/n)?:");
        // getchar();
        scanf("%c",&ch);
        (ch == 'y')?req(p,work,np,nr):printf("\nBye\n");
    }
    return 0;
}
