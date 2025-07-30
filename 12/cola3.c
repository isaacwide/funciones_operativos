#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
/*#include<string.h>*/
#include<unistd.h>

#define TAM_BUF 512

struct mensaje{
    long tipomsg;
    char msg[TAM_BUF];
};

/*leer un mensaje de una cola de mensajes creada previamente*/

int main(int argc, char *argv[]){

	int idcola;
	int tam;
	struct mensaje buffer;

	if(argc != 2){
		puts("MODO DE EMPLEO para leer_cola se necesita <identificador de cola>");
		exit(-1);
	}
	idcola = atoi(argv[1]);
	tam = msgrcv(idcola,&buffer,TAM_BUF,0,0);

	if(tam>0){
		printf("Leyendo idcola %05d\n", idcola);
		printf("\t tipo de mensaje: %05d\n",(&buffer)->tipomsg);
		printf("\t Texto del mensaje: %s\n",(&buffer)->msg);
	}else{
		perror("msgrcv");
		exit(-1);
	}
	exit(0);

}