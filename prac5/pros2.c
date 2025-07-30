#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>


int main (){
	system("clear");
	fprintf(stderr,"1.- inicia el programa con proceso padre : %ld",(long)getpid());
	if(fork()==0){

		fprintf(stderr,"\n2.-inicia el proceso hijo con pid : %ld y padre pid: %ld",(long)getpid(),(long)getppid());
		sleep(2);
		fprintf(stderr,"\n4.-nuevamente el proceso hijo pid: %ld y padre pid %ld",(long)getpid(),(long)getppid);
		exit(0);
	}else{

		fprintf(stderr,"\n3.-continuan el padre  padre pid: %ld y hijo :%ld",(long)getppid(),(long)getpid());
                sleep(2);
		fprintf(stderr,"\n5.-ahora finaliza el padre  padre pid: %ld y hijo :%ld",(long)getppid(),(long)getpid());
                exit(0);



	}

}
