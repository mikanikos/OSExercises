#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;

	for (int i = 0; i<10; i++) {
		pid = fork();
		if (pid < 0) {
			perror("Error");
			exit(2);
		}
		if (pid == 0) {
			sleep(1);
			printf("Son: #%d", i+1);
			sleep(1);
			exit(101 + i);
		}
	}

	for(int i=0; i<10; i++){
		int status;
		wait(&status);
		printf("Process terminated %d\n", WEXITSTATUS(status));
	}


}
