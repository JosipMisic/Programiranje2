#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h>


typedef struct pravokutnik {
	float a, b, P, O;
} PRAVOKUTNIK;

int main() {
	PRAVOKUTNIK pravokutnik;

	printf("Unesi stranicu a: ");
	scanf("%f", &pravokutnik.a);

	printf("Unesi stranicu b: ");
	scanf("%f", &pravokutnik.b);

	pravokutnik.P = pravokutnik.a * pravokutnik.b;
	pravokutnik.O = 2 * (pravokutnik.a + pravokutnik.b);

	printf("\nPovrsina: %.2f", pravokutnik.P);
	printf("\nOpseg: %.2f", pravokutnik.O);

	return 0;
}

#include <stdio.h> 
#include <string.h>

typedef struct razred {
	char ime[20];
	char prezime[20];
	long int mbroj;
	float prosjek;
	char datumRodjenja[13];
} RAZRED;

int main() {

	int n;
	printf("Unesi broj ucenika: ");
	do {
		scanf("%d", &n); getchar();
	} while (n < 1 || n > 40);

	RAZRED ucenik[40];

	int i;
	for (i = 0; i < n; i++) {
		printf("Unesite ime %d. ucenika\n", i + 1);
		scanf("%19s", ucenik[i].ime); getchar();
		printf("Unesite prezime %d. ucenika\n", i + 1);
		scanf("%19s", ucenik[i].prezime); getchar();
		printf("Unesite maticni broj %d. ucenika\n", i + 1);
		scanf("%13ld", &ucenik[i].mbroj); getchar();
		printf("Unesite prosjek %d. ucenika\n", i + 1);
		scanf("%f", &ucenik[i].prosjek); getchar();
		printf("Unesite datum rodjenja %d. ucenika\n", i + 1);
		scanf("%12s", ucenik[i].datumRodjenja); getchar();
	}
	RAZRED najboljiProsjek = ucenik[0];

	for (i = 0; i < n; i++) {
		if (ucenik[i].prosjek > najboljiProsjek.prosjek) {
			najboljiProsjek = ucenik[i];
		}
	}

	printf("\nREZULTATI: \n");
	printf("%s\t", najboljiProsjek.ime);
	printf("%s\t", najboljiProsjek.prezime);
	printf("\n%ld\t", najboljiProsjek.mbroj);
	printf("\n%.2f\t", najboljiProsjek.prosjek);
	printf("\n%s\t", najboljiProsjek.datumRodjenja);

	return 0;
}