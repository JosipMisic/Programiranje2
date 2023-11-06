#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

// Zadatak baš nema smisla jer da bi matrica imala glavnu i
// sporednu dijagonalu mora biti kvadratna, a ako su m i n
// razliciti brojevi onda matrica nece biti kvadratna...

int main() {
	srand((unsigned)time(NULL));
	short rows, cols;
	do {
		rows = lowerLimit + (float)rand() / RAND_MAX * (upperLimit - lowerLimit);
	} while (rows <= 3 || rows > 18);

	do {
		cols = lowerLimit + (float)rand() / RAND_MAX * (upperLimit - lowerLimit);
	} while (cols <= 3 || cols >= 25);

	short** matrix = zauzimanjeMatrice(rows, cols);
	popunjavanjeMatrice(matrix, rows, cols);
	short max = najveciParniBroj(matrix, rows, cols);
	novaMatrica(matrix, rows, cols, max);
	ispisMatrice(matrix, rows, cols);
	matrix = brisanjeMatrice(matrix, rows);

	return 0;
}