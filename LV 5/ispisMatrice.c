#include <stdio.h>
void ispisMatrice(short** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%hd\t", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}