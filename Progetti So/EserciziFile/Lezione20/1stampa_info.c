#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int status;
	pid_t pidf1, pidf2, pidn;

	pidf1 = fork();

	if (pidf1 < 0) {
		perror("Error");
		exit(2);
	}
	else {
		if (pidf1 == 0) {
			printf("child: I am the son of the first father\n");
			pidn = fork();
			if (pidn == 0) {
				execlp ("./stampa_info","stampa_info", "nipote", (char *) 0);
				exit (0);
			}
			wait(&status);
			exit(pidn);
		}
		else {
			printf("parent: I am the first father\n");
			wait(&status);
		}
	}

	pidf2 = fork ();

	if (pidf2 == 0) {
		execlp ("./stampa_info","stampa_info", "figlio", (char *) 0);
		exit (0);
	}
	else {
		printf("Sono il secondo processo padre\n");
		wait (&status);
	}
	return 0;
}
