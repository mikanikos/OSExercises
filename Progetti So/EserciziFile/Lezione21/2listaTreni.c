#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int test_train(char* T) {
	if(strlen(T) != 6 ) {
		return 0;
	}
	char tipo[3];
	strncpy(tipo,T,3);
	tipo[2] = '\0';
	if(strcmp(tipo,"ic") !=0 && strcmp(tipo,"es") !=0 && strcmp(tipo,"rg") !=0) {
		return 0;
	}
	return 1;
}

int main (int argc, char* argv[]){
	int i, status;
	char tipi [3][3]= {"ic","es","rg"};
	int ntipi[3] = {0,0,0};
	pid_t pid;
	for(i=1; i<argc; i++) {
		pid = fork();
		if (pid < 0)
			perror("Errore");
		else {
			if (pid == 0) {
				exit(test_train(argv[i]));
			}
			else {
				wait(&status);
				if (WEXITSTATUS(status)==1){
					printf("Codice di treno valido: %s\n",argv[i]);
					switch (argv[i][0]) {
					case 'i': ntipi[0]++; break;
					case 'e': ntipi[1]++; break;
					case 'r': ntipi[2]++; break;
					default: ;
					}
				}
				else {
					printf("Codice di treno non valido: %s\n",argv[i]);
				}
			}
		}
	}

	char treni [argc-1][7];
	for ( i = 0; i<argc-1 ; i++){
		strcpy(treni[i], argv[i+1]);
	}
	int t;
	for(t = 0; t < 3;t++){
		if (ntipi[t] > 0) {
			printf("%s inseriti: ",tipi[t]);
			for ( i = 0; i<argc-1 ; i++){
				char tipo [3];
				char codice [5];
				strncpy(tipo,treni[i],2);
				tipo[2]= '\0';
				int k;
				for( k= 2; k<strlen(treni[i]); k++){
					codice[k-2] = treni[i][k];
				}
				codice[strlen(treni[i])-2] = '\0';
				if(strcmp (tipo,tipi[t]) == 0){
					printf("\t %s ",codice);
				}
			}
		}
		printf("\n");
	}
}
