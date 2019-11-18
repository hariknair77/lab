#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char label[10],opcode[10],oprand[10];

int tokeniser(char line[]){
    char token[3][10],*toc;
    int k = 0;    
    toc = strtok(line," ");
    while(toc){
        strcpy(token[k++],toc);    
        toc = strtok(NULL," ");
    }
    if(k == 3){
        strcpy(label,token[0]);
        strcpy(opcode,token[1]);
        strcpy(oprand,token[2]);
    }
    else if(k == 2){        
        strcpy(opcode,token[0]);
        strcpy(oprand,token[1]);
    }
    else{
        strcpy(opcode,token[0]);
        strcpy(oprand,"-");
    }
    return k;
}

int main(){
    char op[] = "start  0000";
    int res = tokeniser(op);
    printf("%s\n",opcode);
    printf("%s\n",oprand);
    return 0;
}