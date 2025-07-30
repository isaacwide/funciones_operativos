#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *funcionThread(void *parametro);

int contador=0;


int main(){

pthread_t idhilo;
int error;

error=pthread_create(&idhilo,NULL,funcionThread,NULL);

if(error !=0){
   perror("no se puedo crear un hilo");
   exit(-1);

}

while(contador<10){
   contador++;
   printf("\n incrementa proceso padre: %d\n",contador);
   sleep(1);   

}
exit(0);


}
void *funcionThread(void *parametro){
   while(contador<10){
     contador++;
     printf("\n ahora quien incrementa es el profeso hilo : %d\n",contador);
     sleep(2);
   }
 exit(0);

}
