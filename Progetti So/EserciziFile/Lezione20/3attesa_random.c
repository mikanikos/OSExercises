#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pidf1, pidf2, pidn1, term1, term2;
	int status1, status2;
	pidf1 = fork();

	if (pidf1 < 0) {
		perror("Error");
		exit(2);
	}
	else {
		if (pidf1 == 0) {
			printf("My id: %d\n", getpid());
			execl ("./stampa_argv", "stampa_argv", "Parametro_#1", "Parametro_#2", "Parametro_#3", NULL);
			exit(-1);
		}
		else {
			pidf2 = fork();
			if (pidf2 < 0) {
				perror("Error");
				exit(2);
			}
			else {
				if (pidf2 == 0) {
					pidn1 = fork();
					if (pidn1 < 0) {
						perror("Error");
						exit(2);
					}
					else {
						if (pidn1 == 0) {
							printf("My id: %d\n", getpid());
							sleep(rand()%5);
							exit(2);
						}
						else {
							printf("My id: %d\n", getpid());
							exit(1);
						}
					}
				}
				else {
					term1 = wait(&status1);
					term2 = wait(&status2);
					printf ("Ordine di terminazione dei primi due figli: 1: %d - 2: %d\n", term1, term2);
					exit (0);
				}
			}
		}
	}
}
