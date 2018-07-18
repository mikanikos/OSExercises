#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef char stringa[20];
stringa name;

char* get_name(stringa file) {
	int i, cont = 0;
	for (i = 0; file[i] != '.'; i++)
		name[i] = file[i];
	return name;
}

int main(int num, char* vect[]) {
	pid_t pid, pid2;
	int i, status;

	for(i=0; i<num; i++) {
		pid = fork();
		if (pid < 0) {
			perror("Error");
			exit(2);
		}
		if (pid == 0) {
			pid2 = fork();
			if (pid2 < 0) {
				perror("Error");
				exit(2);
			}
			if (pid2 == 0) {
				execl ("/usr/bin/gcc", "/usr/bin/gcc", vect[i], "-o", get_name(vect[i]), (char*)0);
				exit(1);
			}
			else {
				int terminated_pid = wait(&status);
				if (WEXITSTATUS(status)==0){
				execl(get_name(vect[i]), get_name(vect[i]),(char*)0);
				perror("esecuzione");
				exit(1);
				}
			}
		}
		else {
			printf("procedo con il file: %s\n",vect[i]);
			wait(&status);
		}
	}
	return 0;
}
