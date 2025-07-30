#include<signal.h>
#include<unistd.h>
#include<stdio.h>



void atrapa(int);

int main(){


  int i ;
  signal(SIGALRM,atrapa);//alarmas
  printf("identificativo de proceso : %d \n",getpid());
  alarm(5);
  pause();
  alarm(3);
  pause();
  for(i=0;i<10;i++){
       alarm(1);
       pause();
  }
}
void atrapa(int sig){
   signal(sig,atrapa);
   printf("jingle bell\n");
   fflush(stdout);

}




