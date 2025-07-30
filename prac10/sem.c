#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>

# define sem_hijo 0 
#define sem_padre 1

int main(int argc , char *argv[]){

  int i= 10 , semid,pid;

  struct sembuf opera;

  key_t llave;
/*peticion de identificador con dos semaforos */
  llave = ftok(argv[0],'k'); /*arv sera el nombre del ejecutable */
  
  if((semid=semget(llave,2,IPC_CREAT|0666))==-1){/*se crea el semaforo */
           perror("semget");
           exit(-1);

  }

  /*inicializa de dos semaforos*/
  /*se cierra el semaforo del proceso hijo */
  semctl(semid,sem_hijo,SETVAL,0);/*que queromoa hacer y que valor le damos inical */
  /*set val pone un valor al semaforo */
  /*abir el semaforo padre */
  semctl(semid,sem_padre,SETVAL,1);

  system("ipcs -a");

  /*creacion del proceso padre */
  
  if ((pid=fork())==-1){
     
    perror("fork");
    exit(-1);

  }else if (pid==0){
    opera.sem_flg=0;
    while(i){
        /*se cierra eñ semaforo del hijo */
        opera.sem_num=sem_hijo;
        opera.sem_op=-1;
        semop(semid,&opera,1);
        printf("proceso hijo %d \n",i--);
        /*abre el proceso padre*/
        opera.sem_num=sem_padre;
        opera.sem_op=1;
        semop(semid,&opera,1);
    }
    /*borrando semaforo*/
    semctl(semid,sem_hijo,IPC_RMID,0);
  }else{
    opera.sem_flg=0;
    while(i){
        /*cierra ssemaforo del padre*/
        opera.sem_num=sem_padre;
        opera.sem_op=-1;
        semop(semid,&opera,1);
        printf("proceso padre %d \n",i--);
        /*se habe semaforo del hijo */
        opera.sem_num=sem_hijo;
        opera.sem_op=1;
        semop(semid,&opera,1);
       }
    }
     semctl(semid,sem_padre,IPC_RMID,0);

}


  



