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

void scan(int disk[],int n,int cp,int start,int end){
    int i,j,dist,found=0;
    printf("\n******************************************************\n\t\t\tSCAN\n******************************************************");
    dist = 0;
    mode = 1;
    qsort((void *)disk,n,sizeof(int),comapre);
    printf("\nStart : %d \nend : %d",start,end);  
    printf("\nCurrent postion : %d",cp);  
    printf("\nSorted : ");
    for(i=0;i<n;i++)
        printf("%d  ",disk[i]);    
    printf("\n\nTowards Right\n----------------");
    printf("\nI/O Sequence : "); 
    for(i=0;i<n;i++)
        if(disk[i] >= cp){
            found = 1;
            dist += (abs(cp-disk[i]) + abs(disk[n-1] - disk[i]));
            for(j=i;j<n;j++)
                printf("%d  ",disk[j]);
            break;    
        }
    if(found == 0)
        printf("\n*** oops Cant Go Right!! ***");            
    else{
        if(i != 0){
            dist += abs(end - disk[n-1]) + abs(end-disk[i-1]) + abs(disk[0] - disk[i-1]);
                for(j=i-1;j>=0;j--)
                    printf("%d  ",disk[j]);
        }
    printf("\nTotal Head movement : %d cylinders\n",dist);    
    }         

    //towards left
    dist = 0;
    found = 0;
    printf("\n\nTowards Left\n----------------");
    mode = 0;
    qsort((void *)disk,n,sizeof(int),comapre);  
    printf("\nI/O Sequence : ");  
    for(i=0;i<n;i++)
        if(disk[i] <= cp){
            found = 1;
            dist += (abs(cp-disk[i]) + abs(disk[n-1] - disk[i]));
            for(j=i;j<n;j++)
                printf("%d  ",disk[j]);
            break;    
        }
    if(found == 0)      
        printf("\n*** oops Cant Go Left!! ***");        
    else{
        if(i != 0){
            dist += abs(start - disk[n-1]) + abs(start-disk[i-1]) + abs(disk[0] - disk[i-1]);
                for(j=i-1;j>=0;j--)
                    printf("%d  ",disk[j]);
        }
        printf("\nTotal Head movement : %d cylinders\n",dist);    
    } 
    
}

int main(){
    int start = 0 ,end,cp,n,i,j,tot_cylinders;
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
    scan(disk,n,cp,start,end);
    printf("\n");    
    return 0;
}