// se crea el segmento de memoria compartida 
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>


#define tam_buf 4096
int main(){
   int id;
  printf("Mostando los segmentos de memeoria , antes de crrar u segmento de memoria0");
  system("ipcs -m");


if((id = shmget(IPC_PRIVATE,tam_buf,0666))<0){

     perror("shget");
     exit(-1);
}

printf("identificador del segmento de memoria creado %d \n",id);
system("ipcs -m");
exit(0);



}
