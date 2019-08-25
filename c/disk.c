# include <stdio.h>
# include <stdlib.h>
# include <time.h>

char mode;
typedef struct{
    int flag,track;
}req;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

int comapre(const void *a,const void *b){
    int p = ((req *)a)->track;
    int q = ((req *)b)->track;
    if(mode == 'y')
        return q-p;
    else
        return p-q;
}

int finish(req disk[],int n){
    int i;
    for(i=0;i<n;i++)
        if(disk[i].flag == 0)
            return 1;
    return 0;        
}
void fcfs(req disk[],int n,int cp){
    int i;
    int dist = abs(cp - disk[0].track);
    printf("\n*************\nFCFS\n*************\n");
    printf("\nIO request sequence : ");
    for(i=0;i<n-1;i++){
        printf("%d  ",disk[i].track);
        dist += abs(disk[i].track - disk[i+1].track);
    }
    printf("\nTotal Head movement : %d cylinders\n",dist);
}

void cscan(req disk[],int n,int cp,int start,int end){
    int i,j,dist=0;
    printf("\n*************\nCSCAN\n*************\n");
    qsort((void *)disk,n,sizeof(req),comapre);
    for(i=0;i<n;i++)
        printf("%4d",disk[i].track);
    printf("\nIO request sequence : ");
    //towards big
    if(mode != 'y'){
        for(i=0;i<n;i++)
            if(disk[i].track >= cp){
                dist += (abs(cp-disk[i].track) + abs(end - disk[i].track));
                for(j=i;j<n;j++){
                    disk[i].flag = 1;
                    printf("%d  ",disk[j].track);
                } 
                break;    
            }
        if(finish(disk,n)){
            dist += (end - start) + abs(start-disk[0].track) + abs(disk[0].track-disk[i-1].track);
            for(j=0;j<i;j++)
                printf("%d  ",disk[j].track);
        }    
    }
    else{
        for(i=0;i<n;i++)
            if(disk[i].track <= cp){
                dist += (abs(cp-disk[i].track) + abs(start - disk[i].track));
                for(j=i;j<n;j++)
                    disk[i].flag = 1;
                break;    
            }
        if(finish(disk,n)){
            dist += (end - start) + abs(end-disk[0].track) + abs(disk[0].track-disk[i-1].track);
        }
    }
    printf("\nTotal Head movement : %d cylinders\n",dist);    
}

// void scan(req disk[],int n,int cp,int start,int end){
//     int i,j,dist=0;
//     printf("\nChose mode\n******************\n1.Towards large\n2.Towards small\n");
//     scanf("%c",&mode);
//     qsort((void *)disk,n,sizeof(req),comapre);
//     //towards big
//     if(mode == 1){
//         for(i=0;i<n;i++)
//             if(disk[i].track >= cp){
//                 dist += (abs(cp-disk[i].track) + abs(end - disk[i].track));
//                 for(j=i;j<n;j++)
//                     disk[i].flag = 1;
//                 break;    
//             }
//         if(finish(disk,n))
//             dist += abs(end-disk[0].track);
//     }
//     //towards small..
//     else{
//         for(i=0;i<n;i++)
//             if(disk[i].track <= cp){
//                 dist += (abs(cp-disk[i].track) + abs(start - disk[i].track));
//                 for(j=i;j<n;j++)
//                     disk[i].flag = 1;
//                 break;    
//             }
//         if(finish(disk,n))
//             dist += abs(start-disk[0].track);
//     }
//     for(i=0;i<n;i++)
//         printf("%4d",disk[i].track);
//     printf("\n");
//     printf("\nSCAN = %d ",dist);
// }

int main(){
    int start = 0 ,end,cp,n,i,j,tot_cylinders;
    char ch;
    req *disk;
    srand(time(NULL));
    printf("\nRandom mode(y/n)? : ");
    scanf("%c",&ch);
    if(ch != 'y'){
        printf("\nEnter total number of cylinders : ");
        scanf("%d",&tot_cylinders);
        printf("\nEnter number of i/o requests : ");
        scanf("%d",&n);
        printf("\nEnter current position : ");
        scanf("%d",&cp);
        end = tot_cylinders-1;
        disk = (req*)malloc(n*sizeof(req));
        printf("\nEnter i/o requests : ");
        for(i=0;i<n;i++){
            disk[i].flag = 0;
            scanf("%d",&disk[i].track);
        }        
    }
    else{
        n = randint(5,10);
        tot_cylinders = n*100;
        end = tot_cylinders -1;
        cp = randint(start,end);
        disk = (req*)malloc(n*sizeof(req));
        for(i=0;i<n;i++){
            disk[i].flag = 0;
            disk[i].track = randint(start,end);
        }
    }      
    printf("\nTotal Cylinders : %d ",tot_cylinders);
    printf("\nStart : %d  end : %d",start,end);
    printf("\nCurrent postion : %d",cp);
    printf("\nI/O requests : ");
    for(i=0;i<n;i++)
        printf("%d  ",disk[i].track);
    printf("\n");
    fcfs(disk,n,cp);
    getchar();
    cscan(disk,n,cp,start,end);
    // scan(disk,n,cp,start,end);
    printf("\n");    
    return 0;
}