#include <stdio.h>
#include <stdlib.h> // For exit() function
int main()
{
    char c[1000];
    FILE *fptr;
    if ((fptr = fopen("prg2.txt", "r")) == NULL)
    {
        printf("Error! opening file");
        // Program exits if file pointer returns NULL.
        exit(1);         
    }
    // reads text until newline
    fgets(c,1000,fptr); 
    while(!feof(fptr)){
        fgets(c,1000,fptr);
    printf("Data from the file: %s", c);
    }
    
    fclose(fptr);
    
    return 0;
}