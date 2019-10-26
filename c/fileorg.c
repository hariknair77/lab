#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CL 2

typedef struct node{
    char name[32];
    char type;
    struct node *child[CL];
    struct node *parent;
    int child_count;
    char *data;
}node;
node *root = NULL;
node *pwd = NULL;

void help()
{
	 printf("Available cmds:");
	 printf("\npwd: ");  printf("\tTo print location of present working directory");
	 printf("\nls: ");  printf("\tTo print contents of pwd");
	 printf("\nmkdir: ");  printf("\tTo create new directory in pwd");  printf("\t\t\tUsage: ");  printf("mkdir <dirname>");
	 printf("\nrmdir: ");  printf("\tTo remove directory in pwd");  printf("\t\t\tUsage: ");  printf("rmdir <dirname>");
     printf("\nrm: ");  printf("\tTo remove file");  printf("\t\t\tUsage: ");  printf("rm <filename>");
	 printf("\ntouch: ");  printf("\tTo create new file in pwd");  printf("\t\t\tUsage: ");  printf("touch <filename> <data>");
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
            if(!strcmp(name,pwd->child[i]->name) && pwd->child[i]->type == 'd'){
                printf("Directory already exists\n");
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
    for(i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name) && pwd->child[i]->type == 'f'){
            printf("File already exists\n");
            return;
        }    
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name,name);
    new->type = 'f';
    scanf("%s",data);
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
        if(!strcmp(pwd->name,"/"))
            printf("Cant go back..\n");
        else
            pwd = pwd->parent;
    }
    else if(!strcmp(arg,"/"))
        pwd = root;
    else{
        for(int i=0;i<pwd->child_count;i++)
            if(!strcmp(arg,pwd->child[i]->name)){
                pwd = pwd->child[i];
                return;
            }
        printf("Directory not found\n");
    }
}
void rmdir(){
    char name[32];
    int i;
    scanf("%s",name);
    for(i=0;i < pwd->child_count;i++)
        if(!strcmp(name,pwd->child[i]->name) && pwd->child[i]->type == 'd'){
            if(pwd->child[i]->child_count != 0)
                printf("cant delete [directory not empty]\n");                
            // else{
            //     for(int j=i;j<pwd->child_count;j++)
            //         pwd->child[j-1] = pwd->child[j];
            //     pwd->child_count--;
                
            // }
        }
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
        // else if(!strcmp(cmd,"rm"))
        //     rm();
        
        // }
                
        else if(!strcmp(cmd,"quit"))
            exit(0);
        else
            printf("invalid cmd\n");
    }
    return 0;
}