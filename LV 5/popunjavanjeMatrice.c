#include <stdlib.h>
extern const int matrixLL;
extern const int matrixUL;
void popunjavanjeMatrice(short** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			*(*(matrix + i) + j) = matrixLL + (float)rand() / RAND_MAX * (matrixUL - matrixLL);
		}
	}
}