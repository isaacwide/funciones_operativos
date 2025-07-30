#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>


void *funcionThread(void *parametro);

int main(){

    pthread_t idhilo;
    pthread_attr_t atributos;
    int error;
    /*valor que va a devolver el thread hijo*/
    char *valorDevuelto = NULL;

    /*inicializamos los atributos con sus valores por defecto*/
    pthread_attr_init(&atributos);


   /*aeguramos que el thread que vamos a poder esperar por el thread que vamos a  crear*/
   pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_JOINABLE);

   error=pthread_create(&idhilo,&atributos,funcionThread,NULL);

   if(error !=0){
      perror("error al crear el hilo");
      exit(-1);

   }


   /*el hilo principal espera al hilo hijo*/
   printf("padre: espero al thread a que termine");
   pthread_join(idhilo,(void**)&valorDevuelto);
   printf("padre:ya ha terminado el thread y\n");

   /*se saca en pantall el valor devuelto*/
   printf("padre : devolvio  el hilo \%s\\n",valorDevuelto);

}
void *funcionThread( void *parametro){

/*el hijo espera un segundo y sale */
   printf("hijo espera 1 seg\n");
   sleep(1);
   printf("hijo : termino mi trabajo de hilo\n");
   /*termina el thread y devuelve uan cadena*/
   pthread_exit((void *)"ya termineeee");
}





