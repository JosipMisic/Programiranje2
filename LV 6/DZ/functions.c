#include "MyHeader.h"

void unosBrojaPutovanja(int* brojPutovanja) {
	do {
		printf("Unesite broj putovanja: ");
		scanf("%d", brojPutovanja);
	} while (*brojPutovanja > 10 || *brojPutovanja < 1);
}

PUTOVANJE* alokacijaPutovanja(int brojPutovanja) {
	return (PUTOVANJE*)malloc(brojPutovanja * sizeof(PUTOVANJE));
}

PUTOVANJE* unosPutovanja(PUTOVANJE* const putovanja, int brojPutovanja) {
	PUTOVANJE* max1 = putovanja + 0;
	PUTOVANJE* max2 = putovanja + 0;

	int i, j;
	for (i = 0; i < brojPutovanja; i++) {
		printf("Unesite odrediste:\n");
		scanf("%d", &(putovanja + i)->odrediste);
		printf("Unesite cijenu:\n");
		scanf("%f", &(putovanja + i)->cijena);
		printf("Unesite broj slobodnih mjesta:\n");
		scanf("%d", &(putovanja + i)->brSlobodnihMjesta);
		if ((putovanja + i)->cijena > max1->cijena) {
			max1 = putovanja + i;
		}
		for (j = 0; j < brojPutovanja; j++) {
			if ((putovanja + j)->cijena > max2->cijena && (putovanja + j)->cijena < max1->cijena) {
				max2 = putovanja + j;
			}
		}
	}
	return max1, max2;
}

void ispisPutovanja(PUTOVANJE* jednoPutovanje) {
	printf("cijena: %.2f, odrediste: %d\n",
		jednoPutovanje->cijena,
		jednoPutovanje->odrediste
	);
	printf("cijena: %.2f, odrediste: %d",
		jednoPutovanje->cijena,
		jednoPutovanje->odrediste
	);
}