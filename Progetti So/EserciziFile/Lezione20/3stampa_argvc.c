/* stampa_argv.c */
#include <stdio.h>

int main ( int argc , char* argv[] ) {
	printf ("Nome del programma: %s\n" , argv[0] );
	for(int i=1; i<argc; i++) {
		printf ("Parametro n. %d: %s\n" , i, argv[i]);
	}
}
