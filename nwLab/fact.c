#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <string.h> 
#include <stdlib.h> 
  
long fact(int n){
    if (n==1) return 1;
    else return n*fact(n-1);
}  
int main(int argc , char *argv[] ) 
{ 
    pid_t pid; 
    if (argc != 2) { 
        printf("arg missing or exceeding\n"); 
        exit(0); 
    } 
    int n = atoi(argv[1]);
    if ( atoi ( argv[1] ) <0 ){ 
        printf("negative number entered %d", atoi(argv[1])); 
        exit(0); 
    } 
    pid=fork(); 
    if ( pid<0 ){ 
        printf("failed to create child\n"); 
        exit(0); 
    } 
  
    else if ( pid==0 ) { 
        // long f = fact(n);
        // for(int i=1;i<=n;i++)
        //     fact *= i;
        printf("\nfactorial of %d = %ld\n",n,fact(n));
        exit(0); 
    } 
    // parent process 
    else
    {   
        // long long fact =1;
        // wait(NULL);
        printf("\nPArent : ");
        for(int i=1;i<=n;i++){
            // fact *= i;
            printf("%ld ",fact(i));
        }
        printf("Done\n"); 
    } 
} 