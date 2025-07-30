#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void atrapa(int sig) {
    signal(sig, atrapa);  // Reconfigurar el manejador de señales
    printf("SIGUSR1, magnicidio\n");
    fflush(stdout);  // Forzar la salida del buffer
}

int main() {
    pid_t padre, hijo;
    padre = getpid();
    signal(SIGUSR1, atrapa);

    if ((hijo = fork()) == 0) {
        // Proceso hijo
        sleep(1);  // Esperar un segundo
        kill(padre, SIGUSR1);  // Enviar SIGUSR1 al padre
        sleep(1);
        kill(padre, SIGUSR1);  // Enviar SIGUSR1 al padre
        sleep(1);
        kill(padre, SIGUSR1);  // Enviar SIGUSR1 al padre
        sleep(1);
        kill(padre, SIGKILL);  // Matar al padre
        exit(0);
    } else {
        // Proceso padre
        while (1) {
            pause();  // Esperar a recibir una señal
        }
    }

    return 0;
}
