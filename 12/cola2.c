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
/*enviar un mensaje  una cola de mensaje creada previamente*/

int main(int argc , char * argv[]){
   int idcola;
   int tam;
   struct mensaje buffer;

   if(argc != 2){
      puts("MODO DE EMPLEO envia nombre del prg y <identificador de cola>");
      exit(-1);
   }
   idcola = atoi(argv[1]);
   puts("ingrese un mensaje para publicar:\n");
   if((fgets(buffer.msg, TAM_BUF, stdin) )==NULL){
       puts("no ai mensaje para ser publicado");
       exit(0);
   }
   /*asociar el mensaje ingresado con este proceso*/
    buffer.tipomsg=getpid();
    /*anadir el mensaje al final de la cola*/
    tam=strlen(buffer.msg);

    if((msgsnd(idcola,&buffer,tam,0))<0){
       perror("error puto");
       exit(-1);
    }
    puts("MESAJE RECIBIDO");
    exit(0);
}