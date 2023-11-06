#include "Header.h"

int main(void) {

	srand((unsigned)time(NULL));

	FILE* inFile = openFile("in.txt", "r");

	int rows, cols;
	readMatrixDimens(inFile, &rows, &cols);

	float** matrix = allocateMatrix(rows, cols);

	FILE* outFile = openFile("out.txt", "w");

	inputMatrix(matrix, rows, cols);

	writeMatrix(outFile, matrix, rows, cols);

	fclose(inFile); fclose(outFile);

	return 0;
}