#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX 256

int pid_emisor, pid_receptor;

void envias(int sig) {
    char str[MAX];
    FILE *fp;
    printf("PROCESO EMISOR. MENSAJE: ");
    if (fgets(str, MAX, stdin) != NULL) {
        if ((fp = fopen("buson", "w")) == NULL) {
            perror("envias");
            kill(pid_receptor, SIGTERM);
            exit(1);
        }
        fputs(str, fp);
        fclose(fp);
        signal(SIGUSR1, envias);
        kill(pid_receptor, SIGUSR1);
    } else {
        printf("\n");
        kill(pid_receptor, SIGTERM);
        exit(0);
    }
}

void recibir(int sig) {
    char str[MAX];
    FILE *fp;
    if ((fp = fopen("buson", "r")) == NULL) {
        perror("recibir");
        kill(pid_emisor, SIGTERM);
        exit(1);
    }
    fgets(str, MAX, fp);
    fclose(fp);
    printf("PROCESO RECEPTOR. MENSAJE: %s\n", str);
    signal(SIGUSR1, recibir);
    kill(pid_emisor, SIGUSR1);
}

int main(int argc, char *argv[]) {
    pid_emisor = getpid();
    if ((pid_receptor = fork()) == -1) {
        perror(argv[0]);
        exit(-1);
    } else if (pid_receptor == 0) {
        // Código del receptor
        signal(SIGUSR1, recibir);
        while (1) {
            pause();
        }
    } else {
        // Código del emisor
        printf("Inicializando...\n");
        sleep(2);
        envias(SIGUSR1);
        while (1) {
            pause();
        }
    }
    exit(0);
}
