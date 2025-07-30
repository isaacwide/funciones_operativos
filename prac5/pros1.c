#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    system("clear");
    printf("ID del Proceso: %ld", (long)getpid());
    printf("\nID del Proceso Padre: %ld", (long)getppid());
    printf("\nID del Usuario en el Sistema: %ld", (long)getuid());
    printf("\nID del usuario Efectivo en el Sistema: %ld", (long)geteuid());
    printf("\n\nPulsa para salir...");
    getchar();
    exit(0);
}
