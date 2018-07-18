#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void) {
	pid_t pid;
	FILE *file = fopen( "./test.txt" , "w+" );

	if(file != NULL) {
		pid = fork();
		if (pid < 0) {
			perror("Error");
			exit(2);
		}
		if ( pid == 0 ) {
			char c;
			printf ("[figlio] Attendo 4 secondi...\n");
			sleep ( 4 );
			printf ("\n[figlio] Posizione attuale puntatore file: %ld\n", ftell(file) );
			fseek(file, 0, SEEK_SET);
			printf ("[figlio] Stampo contenuto del file di testo: ");
			c = fgetc ( file );
			while ( ! feof ( file ) ) {
				printf ("%c" , c);
				c = fgetc ( file );
			}
			printf ("\n");
			printf ("[figlio] Chiudo il file ed esco.\n");
			fclose ( file );
			exit ( 0 );
		}
		else {
			printf("[padre] Inserimento stringa nel file");
			fprintf(file, "%s\n", "Sono il padre");
			printf("Offset file: %d", ftell());
			printf("[padre] chiudo il file e lo cancello");
			fclose(file);
			remove("test.txt");
		}
	}
}
