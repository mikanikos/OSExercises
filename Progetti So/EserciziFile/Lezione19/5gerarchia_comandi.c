#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef char stringa[80];
typedef stringa strvett[20];
void gerarchia(int n, strvett vstr);

int main (void) {
	strvett vstr;
	pid_t pid;
	int i, ncom, stato;

	printf("quanti comandi? ");
	scanf("%d", &ncom);
	for(i=0; i<ncom; i++) {
		printf("\ndammi il prossimo comando(senza argomenti)");
		scanf("%s", vstr[i]);
	}
	gerarchia(ncom, vstr);
	pid=wait(&stato);
	exit(0);
}

void gerarchia (int n, strvett vstr) {
	pid_t pid;
	int stato;

	pid = fork();
	for (int i=0; i<20; i++) {
		pid = fork();
		if (pid < 0) {
			perror("Error");
			exit(2);
		}
		if (pid == 0) {
			if (n==-1) /* processo foglia */ {
				printf("\nfoglia %d \n", getpid());
				exit(0);
			}
			else /*attivazione di un nuovo comando*/ {
				pid=gestoresequenza(n-1, vstr);
			}
		}
		else {
			printf("\nProcesso %d per comando %s", pid, vstr[n]);
			pid=wait(&stato);
			get_stato(stato,pid);
			if (execlp(vstr[n], vstr[n], (char *)0) < 0) {
				perror("exec");
				exit(-1);
			}
			exit(0);
		}
	}
	exit(0);
}
