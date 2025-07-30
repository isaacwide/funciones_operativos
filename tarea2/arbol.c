#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    printf("soy el padre = [%d]\n", getpid());

    for (int i = 0; i < 3; i++) {
        if ((pid = fork()) == 0) {
            printf("soy [%d] y mi padre es [%d]\n", getpid(), getppid());
            if (i == 1) {
                if ((pid = fork()) == 0) {
                    printf("soy [%d] y mi padre es [%d]\n", getpid(), getppid());
                    for (int j = 0; j < 2; j++) {
                        if ((pid = fork()) == 0) {
                            printf("soy [%d] y mi padre es [%d]\n", getpid(), getppid());
                            if(j==1){
				if((pid=fork())==0){
					printf("soy [%d] y mi padre es [%d]\n", getpid(), getppid());
					break;
				   }

                            }
                            break;
                        }
                    }
                    break;
                }
            }
            break;
        }
    }

    // Esperar a que todos los hijos terminen
    while (wait(NULL) > 0);

    return 0; 
}
