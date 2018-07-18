#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	pid_t pid;
	int u;
	pid = fork();

	if (pid < 0) {
		perror("Error");
		exit(2);
	}
	else {
		if (pid == 0) {
			printf("child: I am the son\n");
			printf("My id: %d, Parent id = %d\n", getpid(), getppid());
			scanf("%d", &u);
			exit(u);
		}
		else {
			sleep(5);
			printf("parent: I am the father\n");
			printf("My id: %d, Son id = %d\n", getpid(), pid);
			wait(&u);
			printf("PARENT: child exit status :%d\n", WEXITSTATUS(u));
		}
	}
	return 0;
}
