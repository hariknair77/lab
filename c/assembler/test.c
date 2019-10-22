#include <stdio.h>
#include <string.h>
#include <stdlib.h> // For exit() function
int main()
{
    char a[]="c'ABC'",obj[15],res[15]="";
    // int i=0;
    // while(a[i]!='\0'){
    // sprintf(obj,"%x",a[i]);
    // strcat(res,obj);
    // i++;

    // }
    // printf("%s",res);
    char *b = a;
    b+=2;
    int i=0;
    while(b[i++]!='\0');
    b[i-2] = '\0';
    printf("%s",b);
    return 0;
}

