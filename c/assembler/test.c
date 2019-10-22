#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit() function
int main()
{
    char a[]="data,x",obj[15],res[15]="";
    int i =0;
    while(a[i++]!='\0');
    printf("%c",a[i-3]);
    return 0;
}

