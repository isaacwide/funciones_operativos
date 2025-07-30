#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#define llave 234
#define max 10

int main(){

   int shmid ,i ;
   key_t key=llave;
   char * vector;

   // creacionde memoria compartida 
   shmid=shmget(key,(max *sizeof(char)),IPC_CREAT | 0600);
   if(shmid == -1){
       printf("no se ha podido crear el segmento ");
       exit(-1);
   }else{
    // conexxion del segmento 
    if(vector == (char*)0){
      printf("error en crear la conexion");
     exit(-1);

    }
    //manipulacion del segmento de memoria compartida 
    for(i=0;i<max;i++)
        vector[i]='a'+i;
    for(i=0;i<max;i++)
        printf("valor almacenado %c\n",vector[i]);

     if(shmdt(vector)==-1){
              printf("error en la desconexxion");
              exit(-1);
     }else

        printf("exito en la desconexion \n");
        
         if(shmctl(shmid,IPC_RMID,0)==-1){
               printf("error al elimirnar secmeot\n");
               exit(-1);
         }else{
            printf("ya se elimino a a verga \n");
         }  
   }

}