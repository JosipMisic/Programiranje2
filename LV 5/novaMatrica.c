void novaMatrica(short** matrix, int rows, int cols, short max) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (i + j < cols - 1) {
				*(*(matrix + i) + j) = max;
			}
		}
	}
}