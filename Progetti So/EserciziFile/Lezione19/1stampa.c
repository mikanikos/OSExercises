#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		perror("Error");
		exit(2);
	}
	else {
		if (pid == 0) {
			printf("I am the son\n");
			exit(0);
		}
		else {
			printf("I am the father\n");
			exit(0);
		}
	}
}
