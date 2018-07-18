#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) {
		perror("Error");
		exit(2);
	}
	else {
		if (pid == 0) {
			printf("My id: %d, Parent id = %d\n", getpid(), getppid());
			exit(24);
		}
		else {
			printf ("Waiting\n");
			pid = wait (&status);
			printf("Son id: %d, return value = %d.\n", pid, status/256);
			exit(0);
		}
	}
}
