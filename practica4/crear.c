#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <nombre_del_directorio>\n", argv[0]);
        exit(-1);
    }

    if (mkdir(argv[1], 0755) == 0) {
        printf("Directorio '%s' creado exitosamente.\n", argv[1]);
    } else {
        perror("Error al crear el directorio");
        exit(-1);
    }

    return 0;
}
