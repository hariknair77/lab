#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 50

char label_addr [10];
char mnemonic[][10]={"","ADD","ADDF","ADDR","AND","CLEAR","COMP","COMPF","COMPR","DIV","DIVF","DIVR","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","MULR","OR","RD","RMO","RSUB","SHIFTL","SHIFTR","STA","STB","STCH","STF","STL","STS","STSW","STT","STX","SUB","SUBF","SUBR","TD","TIX","TIXR","WD","FIX","FLOAT"};
const char hex[][3]={"","18","58","90","40","B4","28","88","A0","24","64","9C","3C","30","34","38","48","00","68","50","70","08","6C","74","04","D0","20","60","98","44","D8","AC","4C","A4","A8","0C","78","54","80","14","7C","E8","84","10","1C","5C","94","E0","2C","B8","DC","C4","C0"};

int is_opcode(char op[]){
    for(int i=0;i<sizeof(mnemonic)/10;i++)
        if(!strcmp(op,mnemonic[i]))
                return i;
	return 0;
}

int find_sym(char s[]){
    FILE *sym;
    sym = fopen("symtab.txt","r");
    char label[10],addr[10];
    while(!feof(sym)){
        fscanf(sym,"%s%s",label,addr);
        if(!strcmp(s,label)){
            strcpy(label_addr,addr);
            return 1;
        }
    }
    return 0;
}

int main(){
    FILE *temp,*obj,*list,*len;
    char addr[10], opcode[10], operand[10],length[10],prg_name[7]="------",obj_code[15];  
    int start_addr=0,index,size=0,i; 
    temp = fopen("temp.txt","r");
    obj = fopen("obj.txt","a");
    list = fopen("list.txt","a");
    len = fopen("len.txt","r");
    fscanf(len,"%s",length);
    fscanf(temp, "%s%s%s", addr, opcode, operand);
    if(!strcmp("START",opcode)){
        if(strcmp("-",addr))
            strcpy(prg_name,addr);
        start_addr = atoi(operand);
        fprintf(list,"%s %s",opcode,operand); 
        fscanf(temp, "%s%s%s", addr, opcode, operand);
    }
    fprintf(obj,"H^%s^%06x^%s",prg_name,start_addr,length);
    fprintf(obj,"\nT^%06x",start_addr);
    while(!feof(temp)){
    label : index = is_opcode(opcode);                              //search optab for opcode 
        if(index){       
            obj_code[0] = '\0';                                         
            size += 3;
            if(strcmp("-",operand)){                        //searching for symbol...
                if(!find_sym(operand)){                     //invalid label
                    strcpy(label_addr,"0000");
                    printf("Error [undefined symbol] on line : \n");
                }                                          //else label is available [see label_addr]
            }
            else                                            //no label
                strcpy(label_addr,"0000");    
            sprintf(obj_code,"%s%s",hex[index],label_addr);
            // if(size<30)
            //     fprintf(obj,"^%s%s",hex[index],label_addr); //assemble the object code 
            // else{
            //     fprintf(obj,"\nT^%06x^00",start_addr);
            //     fprintf(obj,"^%s%s",hex[index],label_addr);                
            //     size = 3;
            // }
        }
        else if(!strcmp(opcode,"WORD")){
            obj_code[0] = '\0';
            sprintf(obj_code,"%06x",atoi(operand));
            // if(size<30)
            //     fprintf(obj,"^%06x",atoi(operand)); //assemble the object code             
            // else{
            //     fprintf(obj,"\nT^%06x^00",start_addr);
            //     fprintf(obj,"^%06x",atoi(operand)); //assemble the object code                          
            //     size = 3;
            // }
        }
        else if(!strcmp(opcode,"BYTE")){
            obj_code[0] = '\0';
            char *opr = operand;
            opr += 2;
            i = 0;            
            while(opr[i++] != '\0');
            opr[i-2] = '\0';
            if(operand[0] == 'x')
                sprintf(obj_code,"%s",opr);         
            else{
                
                char obj_[20] ="";
                i = 0;
                while(opr[i] != '\0'){
                    sprintf(obj_,"%x",opr[i]);
                    strcat(obj_code,obj_);
                    i++;
                }
            }
            // printf("%s\n",obj_code);
            // if(size<30)
            //     fprintf(obj,"^%06x",atoi(operand)); //assemble the object code             
            // else{
            //     fprintf(obj,"\nT^%06x^00",start_addr);
            //     fprintf(obj,"^%06x",atoi(operand)); //assemble the object code                          
            //     size = 3;
            // }
        }        
        if(size<30 && (strcmp("RESW",opcode) && strcmp("RESB",opcode))){
            fprintf(obj,"^%s",obj_code); //assemble the object code 
            obj_code[0]='\0';
        }   
         
            else{
                while(!strcmp("RESW",opcode) || !strcmp("RESB",opcode))
                    fscanf(temp, "%s%s%s", addr, opcode, operand);
                
                fprintf(obj,"\nT^00%s",addr);
                goto label;
                // fprintf(obj,"^%s",obj_code); //assemble the object code                 
                // size = 3;
            }
        fscanf(temp, "%s%s%s", addr, opcode, operand);
    }    
    return 0;

}