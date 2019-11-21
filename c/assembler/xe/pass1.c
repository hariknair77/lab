#include <stdio.h> 
#include <stdlib.h> //for atoi
#include <string.h> 
#include <ctype.h> //for isspace
#define MAX 50  // line[MAX] => store each line from file 

char label[10],opcode[10],oprand[10]; 

//leave first element blank for indexing purpose 
//is_opcode() return index, that is used to check opcode is valid or not 
//2D array-- number of rows will be figured out from right side 
char mnemonic[][10]={"","ADD","ADDF","ADDR","AND","CLEAR","COMP","COMPF","COMPR","DIV","DIVF","DIVR","FIX","FLOAT","HIO","J","JEQ","JGT","JLT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDX","LPS","MUL","MULF","MULR","NORM","OR","RD","RMO","RSUB","SHIFTL","SHIFTR","SIO","SSK","STA","STB","STCH","STF","STI","STL","STS","STSW","STT","STX","SUB","SUBF","SUBR","SVC","TD","TIO","TIX","TIXR","WD"};
//leave first element blank for indexing purpose 
//is_opcode() return index, that is used to check opcode is valid or not 
int len[]={0,3,3,2,3,2,3,3,2,3,3,2,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,1,3,3,2,3,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2,3,1,3,2,3};
//leave first element blank for indexing purpose 
//is_opcode() return index, that is used to check opcode is valid or not 
char hex[][3]={"","18","58","90","40","B4","28","88","A0","24","64","9C","C4","C0","F4","3C","30","34","38","48","00","68","50","70","08","6C","74","04","D0","20","60","98","C8","44","D8","AC","4C","A4","A8","F0","EC","0C","78","54","80","D4","14","7C","E8","84","10","1C","5C","94","B0","E0","F8","2C","B8","DC"};

//used to remoce leading and trailing white spaces... 
// to return string fro function return type should be char  pointer (char *)
char* trim(char *string){
    //isspace return non-zero if the char is a space 
    while(isspace(string[0])) //remove leading white spaces
        string++; //first char is space so check the next one 
    int len = strlen(string);
    //to remove trailing white spaces
    while(len>0 && isspace(string[len-1])) //oops last one is space 
        len--; //move back.... :)
    string[len] ='\0'; //set last char manually, THE STRING END('\0')
    return string; 
}
//return number of tokens... input is string 
int tokeniser(char line_[]){ 
    //white spaces blah.. get rid of them... 
    char *line = trim(line_);
    char token[3][10],*toc; //array to store tokens temporarly... 
    int k = 0;    //number of tokens.. 
    toc = strtok(line," "); //split line : delim - ' '
    while(toc){
        strcpy(token[k++],toc);   // add to token array..increment number of tokens
        toc = strtok(NULL," ");   //this is synatx cant do anything, ie second time strtok take string as NULL IDK Y?
    }
    //copy tokens to label,opcode and operand arrays.. global 
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
        strcpy(oprand,"-"); // no operand eg RSUB 
    }
    return k; //return token count will be stored in variable -> m
}

int is_opcode(char *op){
    if(op[0] == '+') //4 byte instruction, skip first character... 
        op++;
    for(int i=0;i<sizeof(mnemonic)/10;i++)
        if(strcmp(op,mnemonic[i])==0){
                return i; // return opcode index, used to get length and hexa code from len[] and hex[]
            }
	return 0; //invalid opcode 
}
int find_length(char a[]){  
    if (a[0] == 'c' || a[0] == 'C')
        return strlen(a) - 3;
    // else if (a[0] == 'w' || a[0] == 'W')
    //     return 3;
    else
        return (strlen(a) - 3) / 2;
}

int main(){ 
    FILE *f; //input file
    FILE *temp; //output file
    FILE *fp3; //symbol table
    FILE *length; //to store program length

    int i,j,k=0;
    int locctr = 0;
    int lc=0; //line count 
    int m; //number of tokens (label,opcode,operand)

    char line[MAX]; //store line from input file
    char sym[100][10]; //symbol array
    char file[20]; //store file name

    printf("Enter file name : ");
    scanf("%s",file);

    f = fopen(file,"r");     //opening input file
    temp = fopen("temp.txt", "a"); //opening temp file
    fp3 = fopen("symtab.txt", "a"); 
    length = fopen("len.txt","w");

    fgets(line,MAX,f); // read first line from input file
    lc++; //line count to show error occur in any line (if any...)
    m = tokeniser(line); //split line into 3 fields label,opcode and operand
    
    if (strcmp(opcode, "START") == 0){
        fprintf(temp, "%s %s %04x\n", label,opcode,locctr); // write to output file [no labels : put '-' ]
        fgets(line,MAX,f); //reading next line 
        lc++;              //increment line count 
        m = tokeniser(line); //split line 
    }
    while(!feof(f)){
        if (m==3){
        	for(int l=0;l<k;l++)
        		if (strcmp(label,sym[l])==0){        	   
        			printf("Duplicate error on line : %d\n",lc);
                    fgets(line,MAX,f); //reading next line 
                    lc++;              //increment line count 
                    m = tokeniser(line); //split line 
        		}
    		strcpy(sym[k++],label); //copy to sym table
            fprintf(fp3, "%s %04x\n", label, locctr); //write symbol,address to symtab
        }
        	fprintf(temp, "%04x %s %s\n", locctr, opcode, oprand);  //temp,   %04-> zero padding (4 zeros)
        if (!strcmp(opcode, "WORD"))
            locctr += 3;
        else if (strcmp(opcode, "BYTE") == 0)
            locctr += find_length(oprand);  //eg FIRST BYTE c'ABCD' => add 4 to locctr  FIRST BYTE x'ABCD' => add 2 to locctr
        else if (strcmp(opcode, "RESW") == 0)
            locctr += atoi(oprand) * 3;  //eg FIRST RESW 10 => 10*3
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(oprand);  //FIRST RESB 10 => locctr + 10
        else if(is_opcode(opcode)){
            locctr += len[is_opcode(opcode)]; //add length of instruction to locctr => get length from len array
            if(opcode[0]=='+') 
                locctr ++;  // 4 byte instruction add more 1, already added 3 
        } 
        else if(strcmp(opcode,"END") == 0){
        	// fgets(line,MAX,f);      // read next line 
            lc++;                   //increment line count 
         //    m = tokeniser(line);    //split line 
        	break;
        }
        else{
            printf("Invalid Opcode on line : %d\n",lc);
            printf("%s",opcode);
        }
        fgets(line,MAX,f); // read next line 
        lc++; //increment line count 
        m = tokeniser(line); //split line 
    }
    fprintf(length,"%06x",locctr); // save prg length to a file, for second pass 
	return 0; 
} 
