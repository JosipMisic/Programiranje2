#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct putovanje {
	int odrediste;
	float cijena;
	int brSlobodnihMjesta;
}PUTOVANJE;

int main(void)
{
	PUTOVANJE* putovanja, * max1, * max2;

	int brojPutovanja;
	do {
		printf("Unesite broj putovanja: ");
		scanf("%d", &brojPutovanja);
	} while (brojPutovanja > 10 || brojPutovanja < 1);

	putovanja = (PUTOVANJE*)malloc(brojPutovanja * sizeof(PUTOVANJE));
	if (putovanja == NULL) {
		return 1;
	}

	max1 = putovanja + 0;
	max2 = putovanja + 0;

	int i,j;
	for (i = 0; i < brojPutovanja; i++) {
		printf("Unesite odrediste:\n");
		scanf("%d", &(putovanja + i)->odrediste);
		printf("Unesite cijenu:\n");
		scanf("%f", &(putovanja + i)->cijena);
		printf("Unesite broj slobodnih mjesta:\n");
		scanf("%d", &(putovanja + i)->brSlobodnihMjesta);
		if ((putovanja + i)->cijena > max1->cijena) {
			max1 = putovanja + i;}
	for (j = 0; j < brojPutovanja; j++) {
		if ((putovanja + j)->cijena > max2->cijena && (putovanja + j)->cijena < max1->cijena) {
			max2 = putovanja + j;
		}
	}
}

	printf("REZULTATI:\n");
	printf("cijena: %.2f, odrediste: %d\n", max1->cijena, max1->odrediste);
	printf("cijena: %.2f, odrediste: %d", max2->cijena, max2->odrediste);
	free(putovanja);
	return 0;
}