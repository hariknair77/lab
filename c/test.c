#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int main() 
{ 
    FILE *fp4 = fopen("opcode.dat", "r");
    char op[10],hex[2];
    while(!feof(fp4)){
        fscanf(fp4,"%s%s ",op,hex);
        printf("%s%s\n",op,hex);
        if(strcmp("ADsdD",op))
            printf("asas");
    }
    return 0;
} 
