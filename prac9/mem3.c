#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h> 


#define tam_buf 4096


int main(int argc , char *argv[]){
   int id;
   char *buf_agtmemc;
   int salida, i;
   

   if(argc != 2){
    puts("MODO DE EMPLEO : shmat<12>");
    exit(-1);

   }
   id = atoi(argv[1]);
    
    if((buf_agtmemc=shmat(id,0,0))<(char *)0){
       perror("shmat");
       exit(-1);

    }

    if((buf_agtmemc=malloc(sizeof(char)*tam_buf))==NULL){

       perror("malloc");
       exit(-1);
    }

    for(i=0 ; i<tam_buf;i++)
    buf_agtmemc[i]=i%127;
    salida=open("text.c",O_CREAT|O_WRONLY,0600);
    write(salida,buf_agtmemc,tam_buf);
    close(salida);

    printf("Eliminando memoria compartida\n");
    shmctl(id,IPC_RMID,0);

    printf("El sistema de memoria compartida quedo asi \n");
    system("ipcs -m");
    exit(0);


}