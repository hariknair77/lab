# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int mode;
typedef struct{
    int flag,track;
}req;

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

int comapre(const void *a,const void *b){
    int p = ((req *)a)->track;
    int q = ((req *)b)->track;
    if(mode == 1)
        return p-q;
    else
        return q-p;
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
    for(i=0;i<n-1;i++)
        dist += abs(disk[i].track - disk[i+1].track);
    printf("\nFCFS -> %d",dist);
}

void cscan(req disk[],int n,int cp,int start,int end){
    int i,j,dist=0;
    printf("\nChose mode\n******************\n1.Towards large\n2.Towards small\n");
    scanf("%d",&mode);
    qsort((void *)disk,n,sizeof(req),comapre);
    //towards big
    if(mode == 1){
        for(i=0;i<n;i++)
            if(disk[i].track >= cp){
                dist += (abs(cp-disk[i].track) + abs(end - disk[i].track));
                for(j=i;j<n;j++)
                    disk[i].flag = 1;
                break;    
            }
        if(finish(disk,n)){
            dist += (end - start) + abs(start-disk[0].track) + abs(disk[0].track-disk[i-1].track);
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
    for(i=0;i<n;i++)
        printf("%4d",disk[i].track);
    printf("\n");
    printf("\nCSCAN = %d ",dist);
}

int main(){
    int start = 0 ,end = 199,cp,n,i,j;
    char ch;
    req *disk;
    srand(time(NULL));
    printf("\nRandom mode(y/n)? : ");
    scanf("%c",&ch);
    if(ch != 'y'){
        printf("\nStart : ");
        scanf("%d",&start);
        printf("\nEnd : ");
        scanf("%d",&end);
        printf("\nEnter number of requests : ");
        scanf("%d",&n);
        printf("\nEnter current position : ");
        scanf("%d",&cp);
        disk = (req*)malloc(n*sizeof(req));
        printf("\nEnter resources : ");
        for(i=0;i<n;i++){
            disk[i].flag = 0;
            scanf("%d",&disk[i].track);
        }        
    }
    else{
        n = randint(5,10);
        cp = randint(20,180);
        disk = (req*)malloc(n*sizeof(req));
        for(i=0;i<n;i++){
            disk[i].flag = 0;
            disk[i].track = randint(10,180);
        }
    }      
    for(i=0;i<n;i++)
        printf("%4d",disk[i].track);
    printf("\n");
    fcfs(disk,n,cp);
    getchar();
    cscan(disk,n,cp,start,end);
    printf("\n");    
    return 0;
}