# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int randint(int lower,int upper){
    return rand()%(upper-lower+1)+lower;
}

void mul(int a[],int n){
    for(int i=0;i<n;i++)
        a[i] *= 10;
}
int main(){
    char ch;
    scanf("%c",&ch);
    while(ch != 'y'){
        
    scanf("%c",&ch);
    }
    printf("\nheyy");
    return 0;
}