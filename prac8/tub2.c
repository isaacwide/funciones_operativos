#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max 256

int main() {
    int tuberia[2];
    int pid;
    char mensaje[max];

    if (pipe(tuberia) == -1) {
        perror("pipe");
        exit(-1);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(-1);
    } else if (pid == 0) {
        // Proceso hijo (receptor)
        close(tuberia[1]); // Cierra el extremo de escritura
        while (read(tuberia[0], mensaje, max) > 0 && strcmp(mensaje, "fin") != 0) {
            printf("Proceso receptor = %s\n", mensaje);
        }
        close(tuberia[0]);
        exit(0);
    } else {
        // Proceso padre (emisor)
        close(tuberia[0]); // Cierra el extremo de lectura
        while (1) {
            printf("Proceso emisor: ");
            if (fgets(mensaje, max, stdin) != NULL) {
                mensaje[strcspn(mensaje, "\n")] = 0; // Elimina el salto de línea
                if (write(tuberia[1], mensaje, strlen(mensaje) + 1) <= 0) {
                    perror("write");
                    break;
                }
                if (strcmp(mensaje, "fin") == 0) {
                    break;
                }
            } else {
                break;
            }
        }
        close(tuberia[1]);
        exit(0);
    }

    return 0;
}
