#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>


#define max 256



int main(){

  int a[2];
  int b[2];
  int pid;
  char mensaje[max];

  if(pipe(a)==-1 || pipe(b)==-1){
     perror("error");
     exit(-1);
   }
  if((pid==fork())==-1){
     perror("fork");
     exit(-1);
  }
   else if(pid ==0){//proceso hijo
     close(a[1]);
     close(b[0]);
     while(read(a[0],mensaje,max)>0 && strcmp(mensaje,"listo")!=0){
          printf("proceso receptor = %s \n",mensaje);
          strcpy(mensaje,"listo");
          printf("ahi va el mensaje %s\n",mensaje);
          write(b[1],mensaje,strlen(mensaje)+1);
     }
     close(a[0]);
     close(b[1]);

  }else{

   close(a[0]);
   close(b[1]);

   while(printf("proceso emisor,mensaje") !=0 && gets(mensaje) != NULL && write(a[1],mensaje,strlen(mensaje)+1)>0 && strcmp(mensaje,"fin")!= 0)
    do{

   read(b[0],mensaje,max); 
   }while(strcmp(mensaje,"listo")!=0 );
   close(a[1]);
   close(b[0]);
   exit(0);

 }





}
