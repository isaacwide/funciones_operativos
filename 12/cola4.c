#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<unistd.h>

#define TAM_BUF 512

struct mensaje{
      long tipomsg;
      char msg[TAM_BUF];
};
/*elimina cola de mansajes creada previamente*/

int main(int argc , char *argv[]){

    int idcola;
    struct msqid_ds buffer;
    if(argc !=2){
        puts("modo empleado del identificador");
        exit(-1);
    }
    system("ipcs -q");
    idcola=atoi(argv[1]);
    if((msgctl(idcola,IPC_RMID,NULL))<0){
         perror("error");
         exit(-1);
    }
    printf("cola de mensajes %d eliminada\n",idcola);
    system("ipcs -s");
    exit(0);
}
