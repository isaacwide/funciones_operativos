#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

/**/

int main(int argc , char *argv[]){

    int idcola;
    key_t clave;n
    /*crear cola*/
    clave=ftok(argv[0],'K');
    if((idcola = msgget(clave,IPC_CREAT|0666))<0){
          perror("messget:creat");
          exit(-1);
    }
    printf("creada cola de mensajes con identificador = %d \n",idcola);
    /*abre la cola de mensajes nuevaente */
    if((idcola=msgget(clave,0))<0){
           perror("erororo");
           exit(-1);
    }
    printf("abierta una cola de mensaje de identificador = %d\n",idcola);
    system("ipcs -q");
    exit(0);

}