#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef char stringa[80];
typedef stringa strvett[20];


int main (void) {
	pid_t pid;
	strvett vstr;
	int i, ncom;

	printf("quanti comandi? ");
	scanf("%d", &ncom);
	for(i=0; i<ncom; i++) {
		printf("\ndammi il prossimo comando(senza argomenti)");
		scanf("%s", vstr[i]);
	}

	for (i=0; i<20; i++) {
		pid = fork();
		if (pid < 0) {
			perror("Error");
			exit(2);
		}
		if (pid == 0) {
			system(vstr[i]);
			exit(0);
		}
		else {
			//pid = wait(&stato);
		}
		exit(0);
	}
}
