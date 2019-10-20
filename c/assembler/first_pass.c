#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_length(char a[])
{
    if (a[0] == 'c')
        return strlen(a) - 3;
    else
        return (strlen(a) - 3) / 2;
}
int is_opcode(char opcode[]){
	FILE *fp4 = fopen("opcode.dat", "r");
	char op[10],hex[2];
	int flag = 0;
	while(!feof(fp4)){
		fscanf(fp4,"%s",op);
		if(!strcmp(opcode,op)){
			// printf("valid\n" );
			return 1;
		}
	}
	return 0;
}
int main()
{
    FILE *fp1, *fp2, *fp3;
    char label[10], opcode[10], operand[10],sym[100][10];
    int i, j,k=0, locctr, start_addr;
    fp1 = fopen("prg1.txt", "r");
    fp2 = fopen("temp.txt", "a");
    fp3 = fopen("symtab.txt", "a");
    fscanf(fp1, "%s%s%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        locctr = atoi(operand);
        start_addr = locctr;
        fprintf(fp2, "%s %s\n", opcode,operand); //temp
        fscanf(fp1, "%s  %s  %s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
        start_addr = locctr;
    }
    // strcpy(sym[k++],label);
    while (!feof(fp1))
    {
        if (strcmp(label, "-") != 0){
        	for(int l=0;l<k;l++)
        		if (strcmp(label,sym[l])==0){
        			printf("Duplicate error\n");
        			exit(0);
        		}
    		strcpy(sym[k++],label);
            fprintf(fp3, "%s %x\n", label, locctr); //symtab
        }
        // if(strcmp(opcode,"RESW") && strcmp(opcode,"RESB"))
        	fprintf(fp2, "%x  %s  %s\n", locctr, opcode, operand);  //temp
        if (!strcmp(opcode, "WORD"))
            locctr += 3;
        else if (strcmp(opcode, "BYTE") == 0)
            locctr += find_length(operand);
        else if (strcmp(opcode, "RESW") == 0)
            locctr += atoi(operand) * 3;
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);
        else if(is_opcode(opcode) == 1)
            locctr += 3;
        else if(!strcmp(opcode,"END")){
        	fscanf(fp1, "%s  %s  %s", label, opcode, operand);
        	exit(0);
        }
        else{
        	// printf("%s\n",opcode);
        	printf("Invalid Opcode\n");
        	exit(0);
        }
        fscanf(fp1, "%s  %s  %s", label, opcode, operand);
    }

    return 0;
}
