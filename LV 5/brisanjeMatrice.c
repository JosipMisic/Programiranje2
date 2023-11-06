#include <stdlib.h>
void* brisanjeMatrice(short** matrix, int rows) {
	int i;
	for (i = 0; i < rows; i++) {
		free(*(matrix + i));
	}
	free(matrix);
	return NULL;
}