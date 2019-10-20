#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[10],type[1];
    struct node *parent;
    struct node *child[10];
    int child_count;
}node;

int main() 
{ 
    
    return 0;
} 
