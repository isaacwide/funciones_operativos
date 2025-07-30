#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void atrapa(int);

int main(){

	if(signal(SIGINT,atrapa)==SIG_ERR){
		perror("signal");
		exit(-1);
	}
	printf("en espera de ctrl-c\n");//quiero resivir la señal control c 
	pause();

	
}

void atrapa(int sig){

	printf("senal recibida es %d",sig);


}
