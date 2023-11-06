#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int citanje(FILE* fp1) {
	char znak;
	const char* imeDatoteke = "data.txt";
	fp1 = fopen("data.txt", "r");

	if (fp1 == NULL) {
		printf("Datoteka %s ne postoji na disku.\n", imeDatoteke);
		return 0;
	}
	else {
		while ((znak = fgetc(fp1)) != EOF)
			printf("%c", znak);
	}
	fclose(fp1);
}

int brojac(FILE* fp1, FILE* fp2) {
	int br = 0;
	const char* imeDatoteke1 = "data.txt";
	const char* imeDatoteke2 = "brojac.txt";
	char znak;
	fp1 = fopen("data.txt", "r");
	fp2 = fopen("brojac.txt", "w");
	if (fp1 == NULL) {
		printf("Datoteka %s ne postoji na disku.\n", imeDatoteke1);
		return 0;
	}
	if (fp2 == NULL) {
		printf("Datoteka %s se ne moze kreirati.\n", imeDatoteke2);
		return 0;
	}
	else {
		while ((znak = fgetc(fp1)) != EOF)
			br++;
	}
	fprintf(fp2, "Broj znakova u data.txt: %d", br);
	fclose(fp1);
	fclose(fp2);

}