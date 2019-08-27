# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int mode;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

int comapre(const void *a,const void *b){
    int p = *(int *)a;
    int q = *(int *)b;
    if(mode == 1)
        return p-q;
    else
        return q-p;
}

int main(){
    int start = 0 ,end,cp,n,i,j,tot_cylinders,dist;
    char ch;
    int *disk;
    srand(time(NULL));
    printf("Random mode(y/n)? : ");
    scanf("%c",&ch);
    if(ch != 'y'){
        printf("Enter total number of cylinders : ");
        scanf("%d",&tot_cylinders);
        printf("Enter number of i/o requests : ");
        scanf("%d",&n);
        printf("Enter current position : ");
        scanf("%d",&cp);
        end = tot_cylinders-1;
        disk = (int*)malloc(n*sizeof(int));
        printf("Enter I/O requests : ");
        for(i=0;i<n;i++)
            scanf("%d",&disk[i]);
    }
    else{
        n = randint(5,10);
        tot_cylinders = n*100;
        end = tot_cylinders -1;
        cp = randint(start,end);
        disk = (int*)malloc(n*sizeof(int));
        printf("\nTotal Cylinders : %d ",tot_cylinders);
        printf("\nI/O requests : ");
        for(i=0;i<n;i++){
            disk[i] = randint(start,end);
            printf("%d  ",disk[i]);
        }
    }      
    dist = abs(cp - disk[0]);
    printf("\n******************************************************\n");
    printf("\t\t\tFCFS\n");
    printf("******************************************************\n");
    printf("\nStart : %d \nend : %d",start,end);  
    printf("\nCurrent postion : %d",cp);
    printf("\nIO request sequence : ");
    for(i=0;i<n-1;i++){
        printf("%d  ",disk[i]);
        dist += abs(disk[i] - disk[i+1]);
    }
    printf("\nTotal Head movement : %d cylinders\n",dist);
    printf("\n");    
    return 0;
}