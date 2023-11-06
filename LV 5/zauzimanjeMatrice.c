#include <stdlib.h>
short** zauzimanjeMatrice(int rows, int cols) {
	short** matrix = (short**)malloc(rows * sizeof(short*));
	int i;
	for (i = 0; i < rows; i++) {
		*(matrix + i) = (short*)malloc(cols * sizeof(short));
	}
	return matrix;
}