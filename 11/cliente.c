#include<unistd.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define size 255


int main(int argc, char * argv[]){
    int mi_socket,nuevo,numbytes,tam;
    char buffer[size];
    struct sockaddr_in mi_estructura;

    if(argc !=3 ){
        printf("error modo de empleloaosodjdshbijfhesdfjlgrw");
        exit(-1);
    }

    mi_estructura.sin_family=AF_INET;
    mi_estructura.sin_port=htons(atoi(argv[2]));
    inet_aton(argv[1],&(mi_estructura.sin_addr));
    memset(&(mi_estructura.sin_zero),'\0',0);

    mi_socket=socket(AF_INET,SOCK_STREAM,0);
    tam=sizeof(struct sockaddr);
    connect(mi_socket,(struct sockaddr * )&mi_estructura,tam);
    numbytes=recv(mi_socket,buffer,size-1,0);
    buffer(numbytes)='\0';
    printf("%d byts recibubis \n"),numbytes;
    printf("recibido loco %s\n",buffer);
    close(mi_socket);
}














