#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void mostrar(const char *path) {
    DIR *dir;
    struct dirent *entry;

    // Abrir el directorio
    dir = opendir(path);
    if (dir == NULL) {
        perror("Error al abrir el directorio");
        exit(-1);
    }

    printf("Contenido del directorio '%s':\n", path);
    while ((entry = readdir(dir)) != NULL) {
        // Ignorar los directorios "." y ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <directorio>\n", argv[0]);
        exit(-1);
    }
    mostrar(argv[1]);

    return 0;
}
