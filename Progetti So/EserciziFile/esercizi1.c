#include <stdio.h>
#include <stdlib.h>
#include "esercizi1.h"
#include <String.h>

void stampa31(char* file) {
	char nome[20];
	int giorni;
	FILE *pf;
	pf = fopen(file, "r");
	if(pf == NULL) return;
	while(fscanf(pf,"%s %d\n", nome, &giorni) != EOF)
		if(giorni == 31)
			printf("%s ", nome);
	fclose(pf);
}

void stampa31_binario(char* file) {
	int i = 0;
	mese v[12];
	FILE *pf;
	pf = fopen(file, "rb");
	if(pf == NULL) return;
	while(fread(&v[i], sizeof(mese), 1, pf) > 0) {
		if(v[i].giorni == 31)
			printf("%s ", v[i].nome);
		i++;
	}
	fclose(pf);
}

void modificaEsami(char* file, char* matricola) {
	char nome[20];
	int pos;
	int esami;
	FILE *pf;
	pf = fopen(file, "r");
	if(pf == NULL) return;
	while(fscanf(pf,"%s %d\n", nome, &esami) != EOF)
		pos = ftell(pf);
		if(strcmp(matricola, nome)) {
			fseek(pf,pos,SEEK_SET);
			esami++;
			fprintf(pf,"%s %d\n", nome, esami);
		}
	fclose(pf);
}



