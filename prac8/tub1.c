#include<sys/types.h>
#include<wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

 pid_t idproceso;
 int estadohijo;
 int descriptortuberia[2];
 char buffer[100];

 if((pipe(descriptortuberia))==-1){
     perror("no se puedo la tuberia");
     exit(-1);
  }
 idproceso = fork();

  if(idproceso==-1){
      perror("ellol mi senol");
      exit(-1);
  }
  if(idproceso ==0 ){
     close(descriptortuberia[1]);
     read(descriptortuberia[0],buffer,10);
     printf("\nhijo recibido %s\n",buffer);

     exit(0);
  }

  if(idproceso>0){
     close(descriptortuberia[0]);
     printf("Padre :evvio hola\n");
     strcpy(buffer,"hola chiqui baby");//llena bufer con la palabra hola
     write(descriptortuberia[1],buffer,strlen(buffer)+1);//limita la entrada de los buffer
     wait(&estadohijo);//espera hasta que el poceso hijo termine su tarea 
     exit(0);

  }



}

