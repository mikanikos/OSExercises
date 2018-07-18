#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int status;
	char** comando;

	while(1==1) {
		printf("myshell#");
		scanf("%s\n", &comando);
		pid = fork();
	}
	if (pid < 0)
		perror("Errore");
	else {
		if (pid == 0) {
			execlp(comando, comando, NULL);
			exit(0);
		}
		else {
			while( wait(&status) != pid );
		}
	}
	return 0;
}
