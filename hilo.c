#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void){

	pid_t pid;
	int x;
	for(x=1;x<=3;x++){

		pid=fork();

		if(pid){
			printf("Soy el proceso %d\n",getpid());
			sleep(2);
		}else{

			printf("Soy el proceso hijo uwu %d del padre irresponsable %d \n",getpid(),getppid());
			sleep(2);
			exit(0);	
		}
 	}
	return 0;
}
