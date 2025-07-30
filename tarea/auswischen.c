#include <stdio.h>
#include <fcntl.h>
#include<string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void eliminar_directorio(const char *path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("Error al abrir el directorio");
        exit(-1);
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (lstat(full_path, &statbuf) == -1) {
            perror("Error al obtener información del archivo");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            eliminar_directorio(full_path);
        } else {
            if (unlink(full_path) == -1) {
                perror("Error al borrar el archivo");
            }
        }
    }

    closedir(dir);

    if (rmdir(path) == -1) {
        perror("Error al borrar el directorio");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <nombre_del_archivo_o_directorio>\n", argv[0]);
        exit(-1);
    }

    struct stat statbuf;
    if (lstat(argv[1], &statbuf) == -1) {
        perror("Error al obtener información del archivo o directorio");
        exit(-1);
    }

    if (S_ISDIR(statbuf.st_mode)) {
        eliminar_directorio(argv[1]);
        printf("El directorio '%s' ha sido borrado exitosamente.\n", argv[1]);
    } else {
        if (unlink(argv[1]) == 0) {
            printf("El archivo '%s' ha sido borrado exitosamente.\n", argv[1]);
        } else {
            perror("Error al borrar el archivo");
            exit(-1);
        }
    }

    return 0;
}
