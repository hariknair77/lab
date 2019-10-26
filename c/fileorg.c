#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CL 5

typedef struct node{
    char name[32];
    char type;
    struct node *child[CL];
    struct node *parent;
    int child_count;
    char data[255];
}node;
node *root = NULL;
node *pwd = NULL;

void help()
{
	 printf("Available cmds:");
	 printf("\npwd: ");  printf("\tTo print location of present working directory");
	 printf("\nls: ");  printf("\tTo print contents of pwd");
	 printf("\nmkdir: ");  printf("\tTo create new directory in pwd");  printf("\t\t\tUsage: ");  printf("mkdir <dirname>");
	 printf("\nrmdir: "); printf("\tTo remove an empty directory in pwd");printf("\t\tUsage: ");printf("rmdir <dirname>");
     printf("\nrm -r: ");  printf("\tTo remove directory in pwd");  printf("\t\t\tUsage: ");  printf("rm -r <dirname>");
     printf("\nrm: ");  printf("\tTo remove file");  printf("\t\t\t\t\tUsage: ");  printf("rm <filename>");
	 printf("\ntouch: ");  printf("\tTo create new file in pwd");  printf("\t\t\tUsage: ");  printf("touch <filename> <data>");
     printf("\ncat: ");printf("\tTo print data in a file");printf("\t\t\t\tUsage: ");printf("cat <filename>");
	 printf("\nquit: ");  printf("\tQuit the program");
	printf("\n");
}

void init_root(){
    int i;
    root = (node *)malloc(sizeof(node));
    strcpy(root->name,"/");
    for(i=0;i<CL;i++)
        root->child[i] = NULL;
    root->parent = NULL;
    root->type = 'd';
    root->child_count = 0;
    pwd = root;
    printf("root directory intialised\n");
}
void mkdir(){
    int i;
    char name[32];
    scanf("%s",name);
    if(pwd->child_count >= CL)
        printf("Child limit exceeds\n");
    else{
        for(i=0;i < pwd->child_count;i++)
            if(!strcmp(name,pwd->child[i]->name)){
                printf("mkdir: cannot create directory : File exists\n");
                return;
            }    
        node *new = (node *)malloc(sizeof(node));
        strcpy(new->name,name);
        for(i=0;i<CL;i++)
            new->child[i] = NULL;
        new->parent = pwd;
        new->type = 'd';
        new->child_count = 0;
        pwd->child[pwd->child_count] = new;
        pwd->child_count++;
    }
}
void touch(){
    int i;
    char name[32],data[100];
    if(pwd->child_count > CL){
        printf("Child limit exceeds\n");
        return;
    }
    scanf("%s",name);
    scanf("%s",data);
    for(i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name)){
            printf("touch: cannot create file : File exists\n");
            return;
        }    
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name,name);
    strcpy(new->data,data);
    new->type = 'f';
    pwd->child[pwd->child_count] = new;
    pwd->child_count++;
}
void ls(){
    if(pwd->child_count == 0)
        printf("Empty directory\n");
    else{
        for(int i=0;i<pwd->child_count;i++){
        if(pwd->child[i]->type == 'd')
            printf("/%s\t",pwd->child[i]->name);
        else
            printf("%s\t",pwd->child[i]->name);
        }
    }
    printf("\n");
}
void cd(){
    char arg[32];
    scanf("%s",arg);
    if(!strcmp(arg,"..")){
        if(!strcmp(pwd->name,"/"));
        else
            pwd = pwd->parent;
    }
    else if(!strcmp(arg,"/"))
        pwd = root;
    else{
        for(int i=0;i<pwd->child_count;i++){
            if(!strcmp(arg,pwd->child[i]->name))
                if(pwd->child[i]->type == 'd'){
                pwd = pwd->child[i];
                return;
            }
            else{
                printf("Not a Directory\n");
                return;
            }
        }
        printf("Directory not found\n");
    }
}
void rmdir(){
    char name[32];
    int i,j;
    scanf("%s",name);
    for(i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name)){
            if(pwd->child[i]->type == 'f'){
                printf("rmdir: failed to remove : Not a directory\n" );
                return;
            }
            if(pwd->child[i]->child_count != 0){
                printf("rmdir: failed to remove : Directory not empty\n");                
                return;
            }
            else{
                for(j=i;j<pwd->child_count-1;j++)
                    pwd->child[j] = pwd->child[j+1];
                pwd->child_count--;
                return;  
            }
        }
    printf("Directory not found\n");
}
void rm(){
    char name[32];
    int i,j,flag=0;
    scanf("%s",name);
    if(!strcmp(name,"-r")){
        scanf("%s",name);
        flag = 1;
    }
    for(i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name)){
            if(flag == 0 && pwd->child[i]->type == 'd')
                printf("rm: cannot remove : Is a directory\n");
            else{               
                for(j=i;j<pwd->child_count-1;j++)
                    pwd->child[j]->name,pwd->child[j+1]->name;
                pwd->child_count--;
                break;  
            }
        }
}
void cat(){
    char name[32];
    scanf("%s",name);
    for(int i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name) && pwd->child[i]->type == 'f'){
            printf("%s\n",pwd->child[i]->data );
            // printf("%s\n", pwd->child[i]->name);
            return;
        }
    printf("File not found\n");
}
void loc(){
    char tree[100][20];
    int i=0;
    node *p = pwd;
    if(!strcmp(p->name,"/")){
        printf("/\n");
        return;
    }
    while(strcmp(p->name,"/")){
        strcpy(tree[i++],p->name);
        p = p->parent;
    }
    for(int j=i-1;j>=0;j--)
        printf("/%s",tree[j] );
    printf("\n");    
}
int main(){
    char cmd[20];
    init_root();
    while(1){
        printf("/%s> ",pwd->name);
        scanf("%s",cmd);
        if(!strcmp(cmd,"help"))
            help();
        else if(!strcmp(cmd,"mkdir"))
            mkdir();
        else if(!strcmp(cmd,"ls"))
            ls();
        else if(!strcmp(cmd,"cd"))
            cd();
        else if(!strcmp(cmd,"touch"))
            touch();
        else if(!strcmp(cmd,"rmdir"))
            rmdir();
        else if(!strcmp(cmd,"rm"))
            rm();
        else if(!strcmp(cmd,"cat"))
            cat();
        else if(!strcmp(cmd,"pwd"))
            loc();
        else if(!strcmp(cmd,"quit"))
            exit(0);
        else
            printf("invalid cmd\n");
    }
    return 0;
}