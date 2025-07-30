#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

int main(int argc, char * argv[]){

   int idsem;
   if(argc != 2){
      puts("MODO DE EMPLEO :eliminar <idsem>");
      exit(-1);
   }

   idsem=atoi(argv[1]);
    /*eliminar semaforo*/
   if((semctl(idsem,0,IPC_RMID))<0){
     perror("error");
     exit(-1);
   }else{


      puts("semaforo eliminado ");
      system("ipcs -s");
   }
exit(0);

}