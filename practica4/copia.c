#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define PERMS 0666

int main(int argc,char *argv[]){

int f1,f2,n;
char buf[BUFSIZ];

if(argc != 3){
	fprintf(stderr,"uso argv[0] fuente destino \n");
	exit(-1);
}
if((f1=open(argv[1],O_RDONLY))==-1){
	fprintf(stderr,"%s no puedo crear %s \n",argv[0],argv[2]);
	exit(1);
}
if((f2=creat(argv[2],PERMS))==-1){

	fprintf(stderr,"%s no puedo crear %s \n",argv[0],argv[2]);
	exit(1);

}

while((n=read(f1,buf,BUFSIZ))>0)
   	if(write(f2,buf,n)!=n){
 		fprintf(stderr,"%s error de escritura en el archivo %s \n",argv[0],argv[2]);
		exit(2);
	}

return 0;


}
