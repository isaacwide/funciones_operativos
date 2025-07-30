#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <nombre_del_archivo>\n", argv[0]);
        exit(-1);
    }

    if (unlink(argv[1]) == 0) {
        printf("El archivo '%s' ha sido borrado exitosamente.\n", argv[1]);
    } else {
        perror("Error al borrar el archivo");
        exit(-1);
    }

    return 0;
}
