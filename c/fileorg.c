#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
typedef struct node{
    char name[MAX];
    int type;
    struct node *child[10];
    struct node *parent;
}node;

node *root = NULL;
node *pwd = NULL;

void help()
{
	 printf("Available Commands:");
	 printf("\npwd: ");  printf("\tTo print location of present working directory");
	 printf("\nls: ");  printf("\tTo print contents of pwd");
	 printf("\nmkdir: ");  printf("\tTo create new directory in pwd");  printf("\t\t\tUsage: ");  printf("mkdir <dirname>");
	 printf("\nrmdir: ");  printf("\tTo remove directory in pwd");  printf("\t\t\tUsage: ");  printf("rmdir <dirname>");
     printf("\nrm: ");  printf("\tTo remove file");  printf("\t\t\tUsage: ");  printf("rm <filename>");
	 printf("\ntouch: ");  printf("\tTo create new file in pwd");  printf("\t\t\tUsage: ");  printf("touch <filename> <data>");
	 printf("\nquit: ");  printf("\tQuit the program");
	printf("\n");
}

void mkdir(char arg[]){
    int i=0;
    node *new = (node *)malloc(sizeof(node));
    strcpy(new->name,arg);
    for(int i=0;i<10;i++)
        new->child[i] = NULL;
    while(pwd->child[i++] != NULL);
    pwd->child[i] = new;
    new->parent = pwd;
    new->type = 0;
    printf("%s\n",new->name);
    
}
char* getarg(char *string){
    while(!isspace(string[0]))
        string++;
    return string++;
}
void ls(){
    node *temp = pwd;
    int i=0;
    while(temp->child[i++] != NULL){
        if(temp->child[i]->type == 0)
          printf("/%s\n",temp->child[i]->name);
        else
          printf("%s\n",temp->child[i]->name);
    }
}
int main(){
    char command[20],name[10];
    int i;
    printf("File Organization implementation\n");
    node *root = (node *)malloc(sizeof(node));
    printf("Enter root dir : ");
    scanf("%s",root->name);
    for(i=0;i<MAX;i++)
        root->child[i] = NULL;
    root->parent = NULL;
    root->type = 0;
    pwd = root;
    printf("root directory intialised\n");
    // printf("/>");
    getchar();
    while(1){
        printf(">%s",pwd->name);
        fgets(command,MAX,stdin);
        command[strcspn(command,"\n")] = '\0'; 
        // printf("%s\n",command);
        if(!strncmp(command,"help",4))
            help();
        // else if(!strncmp(command,"cd",2))
        //     cd();
        else if(!strncmp(command,"mkdir",5))
            mkdir(getarg(command));
        // else if(!strncmp(command,"rmdir",5))
        //     rmdir();
        // else if(!strncmp(command,"touch",5))
        //     touch();
        // else if(!strncmp(command,"rm",2))
        //     rm();
        else if(!strncmp(command,"ls",2)){
            ls();
        }
                
        else if(!strncmp(command,"quit",4))
            exit(0);
        else
            printf("invalid command\n");
    }
    return 0;
}