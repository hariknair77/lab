#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h> 
#include <unistd.h>

int main(){
	int a = 10,b=20;
	pid_t pid;
	pid = fork();
	if(pid<0){
		printf("oops sorry cant create process\n" );
		exit(-1);
	}

	else if(pid == 0){
		// execlp("/bin/ls","ls",NULL);
		printf("IN child :: a = %d , b = %d \n",a,b );
		printf("child is chaging the values \n");
		a=99;
		printf("changed a = %d \n",a );
		printf("hello from child\n");
	}
	else{
		a = 100;
		b = 200;
		printf("In parent :: a = %d , b = %d \n",a,b );
		wait(NULL);
		printf("child complete..\nnew child\n");
		fork();
		if(pid == 0){
		// execlp("/bin/ls","ls",NULL);
		printf("second hello from child\n");
	}
		
		exit(0);
	}
}