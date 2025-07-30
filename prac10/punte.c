#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/wait.h>  // <-- Añade esta línea para wait()
#include<unistd.h>

#define sem_hijo 0 
#define sem_padre 1

int main(int argc, char *argv[]) {
    int i = 10, semid, pid;
    struct sembuf opera;
    key_t llave;

    /* Petición de identificador con dos semáforos */
    llave = ftok(argv[0], 'k');
    
    if ((semid = semget(llave, 2, IPC_CREAT | 0666)) == -1) {
        perror("semget");
        exit(-1);
    }

    /* Inicialización de los semáforos */
    semctl(semid, sem_hijo, SETVAL, 0);   // Hijo bloqueado inicialmente
    semctl(semid, sem_padre, SETVAL, 1);  // Padre puede empezar

    system("ipcs -s");

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(-1);
    } 
    else if (pid == 0) {  // Proceso hijo
        opera.sem_flg = 0;
        while (i) {
            // Espera señal del padre
            opera.sem_num = sem_hijo;
            opera.sem_op = -1;
            semop(semid, &opera, 1);
            
            printf("Proceso hijo %d\n", i--);
            
            // Libera al padre
            opera.sem_num = sem_padre;
            opera.sem_op = 1;
            semop(semid, &opera, 1);
        }
    } 
    else {  // Proceso padre
        opera.sem_flg = 0;
        while (i) {
            // Espera su turno (inicialmente lo tiene)
            opera.sem_num = sem_padre;
            opera.sem_op = -1;
            semop(semid, &opera, 1);
            
            printf("Proceso padre %d\n", i--);
            
            // Libera al hijo
            opera.sem_num = sem_hijo;
            opera.sem_op = 1;
            semop(semid, &opera, 1);
        }
        
        // Espera a que el hijo termine
        wait(NULL);
        
        // Elimina el conjunto de semáforos
        if (semctl(semid, 0, IPC_RMID) == -1) {
            perror("semctl IPC_RMID");
            exit(-1);
        }
    }

    return 0;
}