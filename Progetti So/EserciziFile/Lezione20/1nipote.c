#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(char** str) {
	if(strcmp(str, "nipote") == 0)
		printf("Sono il nipote del primo padre\n");
	if(strcmp(str, "figlio") == 0)
			printf("Sono il figlio del secondo padre\n");
	return 0;
}
