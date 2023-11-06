#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "Header.h"

static int brojClanova = 0;

int kreiranjeDatoteke(FILE* fp) {
	int z = 0;
	fp = fopen("studenti.bin", "wb+");
	if (fp == NULL) {
		fprintf(stderr, "Vrijednost pogreske je: %d.\n", errno);
		z = -1;
	}
	if (z == 0) {
		fclose(fp);
	}
	return z;
}


void dodavanje(FILE* fp, int n) {
	fp = fopen("studenti.bin", "wb+");
	STUDENT temp = { 0 };
	getchar();
	printf("Unesite ime studenta!\n");
	scanf("%19[^\n]", temp.ime);
	printf("Unesite prezime studenta!\n");
	getchar();
	scanf("%19[^\n]", temp.prezime);
	printf("Unesite adresu studenta!\n");
	getchar();
	scanf("%49[^\n]", temp.adresa);
	fwrite(&temp, sizeof(STUDENT), 1, fp);
	rewind(fp);
	fclose(fp);
}

void citanje(FILE* fp1, FILE* fp2) {
	STUDENT studenti[] = { "", 0.0 };
	int n = sizeof(studenti) / sizeof(STUDENT);

	fp1 = fopen("studenti.bin", "rb");
	fp2 = fopen("studenti.txt", "w");

	fread(studenti, sizeof(STUDENT), n, fp1);


	for (int i = 0; i < n; i++) {
		if (i == 0) {
			fprintf(fp2, "%s %s %s ", studenti[i].ime,
				studenti[i].prezime, studenti[i].adresa);
		}
		else if (i > 0 && i < n - 1) {
			fprintf(fp2, "%s %s %s ", studenti[i].ime,
				studenti[i].prezime, studenti[i].adresa);
		}
		else {
			fprintf(fp2, "%s %s %s", studenti[i].ime,
				studenti[i].prezime, studenti[i].adresa);
		}
	}
	fclose(fp1);
	fclose(fp2);
}


