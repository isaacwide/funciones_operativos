
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
   
    int id;
    char *buf_agtmemc;

    if(argc != 2){
       puts("MODO DE EMPLEO : shmat<12>");
       exit(-1);

    }
    id = atoi(argv[1]);
    
    if((buf_agtmemc=shmat(id,0,0))<(char *)0){
       perror("shmat");
       exit(-1);

    }
    printf("el segmento a sido adosado en en %p\n",buf_agtmemc);
    system("ipcs -m");
    exit(0);


}