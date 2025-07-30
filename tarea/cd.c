#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void cambiar_directorio(const char *path){
	if (chdir(path) == -1) {
       		 perror("Error al cambiar de directorio");
        	exit(-1);
    	} else {
        	printf("Cambiado al directorio: %s\n", path);
    	}
}

int main(int argc, char *argv[]){

	if(argc<2){
		printf("Uso: %s <directorio>\n", argv[0]);
        	exit(-1);
	}

	cambiar_directorio(argv[1]);
}
