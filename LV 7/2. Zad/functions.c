#include "Header.h"

void readMatrixDimens(FILE* inFile, int* rows, int* cols) {
	fscanf(inFile, "%d", rows);
	fscanf(inFile, "%d", cols);
}

FILE* openFile(char* fileName, char* mode) {
	FILE* file = fopen(fileName, mode);
	if (file == NULL) { printf("Greska pri rukovanju s %s.\n", fileName); exit(EXIT_FAILURE); }
	return file;
}

float** allocateMatrix(int rows, int cols) {
	float** matrix = (float**)malloc(rows * sizeof(float*));
	int i = 0;
	for (i; i < rows; i++)
		*(matrix + i) = (float*)malloc(cols * sizeof(float));
	return matrix;
}

void inputMatrix(float** matrix, int rows, int cols) {
	int i;
	int j = 0;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			*(*(matrix + i) + j) = -125.5 + (float)rand() / RAND_MAX * (65.8 - (-125.5));
}

void writeMatrix(FILE* outFile, float** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows - 1; i++) {
		for (j = 1; j < cols; j++) {
			printf("%.2f\t", *(*(matrix + i) + j));
			fprintf(outFile, "%.2f\t", *(*(matrix + i) + j));
		}
		printf("\n");
		fprintf(outFile, "\n");
	}
}