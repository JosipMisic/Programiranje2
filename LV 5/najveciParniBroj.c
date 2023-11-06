short najveciParniBroj(short** matrix, int rows, int cols) {
	short max = *(*(matrix + 0) + 0);
	int i, j;
	int isEven;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (i + j > cols - 1) {
				isEven = *(*(matrix + i) + j) % 2 == 0;
				if (isEven && *(*(matrix + i) + j) > max) {
					max = *(*(matrix + i) + j);
				}
			}
		}
	}
	return max;
}