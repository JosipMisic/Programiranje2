#include "Header.h"

#define DG -100
#define GG 100

void unos(int* redovi, int* stupci) {
	scanf("%d%d", redovi, stupci);
}

float** alokacijaMatrice(int redovi, int stupci) {
	float** matrica = (float**)malloc(redovi * sizeof(float*));
	int i;
	for (i = 0; i < redovi; i++) {
		matrica[i] = (float*)malloc(stupci * sizeof(float));
	}
	return matrica;
}

void popunjavanjeMatrice(float** matrica, int redovi, int stupci) {
	int i, j;
	for (i = 0; i < redovi; i++) {
		for (j = 0; j < stupci; j++) {
			matrica[i][j] = DG + (float)rand() / RAND_MAX * (GG - DG);
		}
	}
}

float nadiMax(float* polje, int n) {
	int i = 0;
	float max = polje[0];
	for (i = 0; i < n; i++) {
		if (polje[i] > max) {
			max = polje[i];
		}
	}
	return max;
}

void transformacijaMatrice(float** matrica, int redovi, int stupci) {
	int i, j;
	float max;
	for (i = 0; i < redovi; i++) {
		max = nadiMax(matrica[i], stupci);
		for (j = 0; j < stupci; j++) {
			matrica[i][j] = max;
		}
	}
}

void* oslobadanjeMatrice(float** matrica, int redovi) {
	int i;
	for (i = 0; i < redovi; i++) {
		free(matrica[i]);
	}
	free(matrica);
	return NULL;
}

void ispisMatrice(float** matrica, int redovi, int stupci) {
	int i, j;
	for (i = 0; i < redovi; i++) {
		for (j = 0; j < stupci; j++) {
			printf("%f\t", matrica[i][j]);
		}
		printf("\n");
	}
}