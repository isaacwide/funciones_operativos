/*kill-l son las 64 señales*/
#include<signal.h>
#include<unistd.h>
#include<stdio.h>



void atrapa(int);


int main(){

	int i;
        for(i=0;i<=64;i++)
                      signal(i,atrapa);
               printf("identificativo de proceso ;%d \n",getpid());
               pause();
               printf("continuando.....\n");
               /*return o ;*/


}
void atrapa (int sig){
      signal(sig,atrapa);
      printf("recibida la señal :%d\n",sig);

}
