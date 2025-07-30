#include<sys/types.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc , char * argv[]){
   mode_t modo= 0666;
   
  if(argc != 2 ){

   puts("uso : newfifo<name>");
   exit(0);
   }
   if((mkfifo(argv[1],modo))<0){
    perror("mkfifo");
    exit(0);

   }
exit(0);

}
