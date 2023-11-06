#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Header.h"

int main() {
	int i;
	int z = 0;
	int n;
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	z = kreiranjeDatoteke(fp1);

	if (z == -1)
		return 1;

	do {
		printf("Unesi broj studenata: ");
		scanf("%d", &n);
	} while (n < 1);
	for (i=0; i<n; i++)
		dodavanje(fp1, n);

	citanje(fp1, fp2);

	return 0;
}