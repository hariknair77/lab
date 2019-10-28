#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 50

char label[10],opcode[10],oprand[10];

char mnemonic[][10]={"","ADD","ADDF","ADDR","AND","CLEAR","COMP","COMPF","COMPR","DIV","DIVF","DIVR","FIX","FLOAT","HIO","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","MULR","NORM","OR","RD","RMO","RSUB","SHIFTL","SHIFTR","SIO","SSK","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SUBR","SVC","TD","TIO","TIX","TIXR","WD"};

int len[]={0,3,3,2,3,2,3,3,2,3,3,2,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1,3,3,2,3,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,3,1,3,2,3};

char hex[][3]={"","18","58","90","40","B4","28","88","A0","24","64","9C","C4","C0","F4","3C","30","34","38","48","00","68","50","70","08","6C","74","04","D0","20","60","98","C8","44","D8","AC","4C","A4","A8","F0","EC","0C","78","54","80","D4","14","7C","E8","84","10","1C","5C","94","B0","E0","F8","2C","B8","DC"};

struct literal{
    char *name,*value,*addr;
    int len;
};
struct literal *littab[100];
int lit_count = 0;
// int hex_to_dec(char *hex){
//     int cnt=0,dec=0,i,dig;
//     for(i=(strlen(hex)-1);i>=0;i--){
//         switch(hex[i]){
//             case 'A':
//                 dig=10; break;
//             case 'B':
//                 dig=11; break;
//             case 'C':
//                 dig=12; break;
//             case 'D':
//                 dig=13; break;
//             case 'E':
//                 dig=14; break;
//             case 'F':
//                 dig=15; break;
//             default:
//                 dig=hex[i]-0x30; //0x30 = '0'
//         }
//         dec= dec+ (dig)*pow((double)16,(double)cnt);
//         cnt++;
//     }
//     return dec;
// }
char *trim(char *string){
    while(isspace(string[0]))
        string++;
    char *final = strdup(string);
    int len = strlen(final);
    while(len>0 && isspace(final[len-1]))
        len--;
    final[len] ='\0';
    return final;
}
int tokeniser(char line_[]){
    char *line = trim(line_);
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

int is_opcode(char *op){
    if(op[0] == '+')
        op++;
    for(int i=0;i<sizeof(mnemonic)/10;i++)
        if(!strcmp(op,mnemonic[i])){
                return i;
            }
	return 0;
}
int find_length(char a[])
{
    if (a[0] == 'c' || a[0] == 'C')
        return strlen(a) - 3;
    else if (a[0] == 'w' || a[0] == 'W')
        return 3;
    else
        return (strlen(a) - 3) / 2;
}

int main() 
{ 
    FILE *f,*temp,*fp3,*fp4,*length;
    int i, j,k=0, locctr = 0, start_addr = 0,m,lc=0,flag;
    char line[MAX],sym[100][10],file[20];
    printf("Enter file name : ");
    scanf("%s",file);
    f = fopen(file,"r");    
    temp = fopen("temp.txt", "a");
    fp3 = fopen("symtab.txt", "a");
    length = fopen("len.txt","w");
    fgets(line,MAX,f);
    lc++;
     m = tokeniser(line); 
    if (strcmp(opcode, "START") == 0)
    {
        // locctr = hex_to_dec(oprand);
        // locctr = 0;
        // start_addr = locctr;
        fprintf(temp, "- %s %04x\n", opcode,start_addr);
        fgets(line,MAX,f);
        lc++;
        m = tokeniser(line); 
    }
    while(!feof(f)){
        flag = 0;
        if(oprand[0] == '='){
            for(int l=0;l<lit_count;l++)
        		if (strcmp(littab[l]->name,oprand)){
        	    // fprintf(temp,"%s%d\n","Duplicate error on line : ",lc);  //temp
        			printf("Duplicate error on line : %d\n",lc);
                    flag = 1;
                    break;
                }
        if(flag == 0){
            struct literal *new = (struct literal *) malloc(sizeof(struct literal));
            new->name = oprand;
            char lit
            new->len = find_length()
            littab[lit_count++] = new;
        }
        }
        if (m==3){
        	for(int l=0;l<k;l++)
        		if (strcmp(label,sym[l])==0){
        	    // fprintf(temp,"%s%d\n","Duplicate error on line : ",lc);  //temp
        			printf("Duplicate error on line : %d\n",lc);
                    fgets(line,MAX,f);
                    m = tokeniser(line);
        		}
    		strcpy(sym[k++],label);
            fprintf(fp3, "%s %04x\n", label, locctr); //symtab
        }
        	fprintf(temp, "%04x %s %s\n", locctr, opcode, oprand);  //temp
        if (!strcmp(opcode, "WORD"))
            locctr += 3;
        else if (strcmp(opcode, "BYTE") == 0)
            locctr += find_length(oprand);
        else if (strcmp(opcode, "RESW") == 0)
            locctr += atoi(oprand) * 3;
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(oprand);
        else if(is_opcode(opcode)){
            locctr += len[is_opcode(opcode)];
            if(opcode[0]=='+') 
                locctr ++;           
        } 
        else if(!strcmp(opcode,"END")){
        	fgets(line,MAX,f);
            lc++;
            m = tokeniser(line);    
        	break;
        }
        else
            printf("Invalid Opcode on line : %d\n",lc);
        fgets(line,MAX,f);
        lc++;
        m = tokeniser(line);
    }
    fprintf(length,"%06x",locctr);
    exit(0);
	return 0; 
} 
