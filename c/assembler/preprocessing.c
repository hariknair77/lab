#include <string.h> 
#include <stdio.h> 
#define MAX 50

char token[3][10],*toc;

int tokeniser(char line[]){
    int k = 0;    
    toc = strtok(line," ");
    while(toc){
        strcpy(token[k++],toc);    
        toc = strtok(NULL," ");
    }
    // for(int i=0;i<k;i++)
    //     printf("%s",token[i]);
    // printf("\nk = %d",k);
    return k;
}

int main() 
{ 
    FILE *f;
    char line[MAX],label[10],opcode[10],oprand[10];
    f = fopen("prg2.txt","r");    
    while(fgets(line,MAX,f)){
        int m = tokeniser(line); 
        // printf("%s %s %s\n",token[0],token[1],token[2]);

        if(m == 3){
            strcpy(label,token[0]);
            strcpy(opcode,token[1]);
            strcpy(oprand,token[2]);
            // printf("3 words\n");
            printf("%s %s %s\n",label,opcode,oprand);
        }
        else if(m == 2){        
            strcpy(opcode,token[0]);
            strcpy(oprand,token[1]);
            // printf("2 words\n");
            printf("%s %s\n",opcode,oprand);
        }
        else{
            // printf("1 words\n");
            strcpy(opcode,token[0]);
            printf("%s\n",opcode);
        }
    }
	return 0; 
} 
