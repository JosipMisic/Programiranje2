#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int** allocateMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);

int* generateRow(int size);
int* convertDecToBin(float random, int sign, int size);
int* calculateCharacteristic(int number);
int* calcMantissa(float number);

int findRowWithMostOnes(int** matrix, int rows, int cols);
void printRow(int** matrix, int row, int cols);

void printMatrix(int** matrix, int rows, int cols);
void* freeMatrix(int** matrix, int rows);

int main() {

	int rows;
	const int cols = 32;
	do {
		printf("Enter the number of rows: ");
		scanf("%d", &rows);
	} while (rows < 2 || rows > 20);

	int** matrix = allocateMatrix(rows, cols);

	srand((unsigned)time(NULL));

	fillMatrix(matrix, rows, cols);

	int rowIndex = findRowWithMostOnes(matrix, rows, cols);
	printRow(matrix, rowIndex, cols);

	printMatrix(matrix, rows, cols);
	
	matrix = freeMatrix(matrix, rows);

	return 0;
}

int** allocateMatrix(int rows, int cols) {
	int** matrix = (int**)calloc(rows, sizeof(int*));
	return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
	int i;
	for (i = 0; i < rows; i++) {
		*(matrix + i) = generateRow(cols);
	}
}

int* generateRow(int size) {
	const int LOWERLIMIT = 1, UPPERLIMIT = 2;
	const int signLowerLimit = 0, signUpperlimit = 1;

	float random = LOWERLIMIT + (float)rand() / RAND_MAX * (UPPERLIMIT - LOWERLIMIT);
	float signLimiter = signLowerLimit + (float)rand() / RAND_MAX * (signUpperlimit - signLowerLimit);;
	int sign;
	if (signLimiter <= 0.5) {
		sign = 0;
	}
	else {
		sign = 1;
	}

	return convertDecToBin(random, sign, size);
}

int* convertDecToBin(float random, int sign, int size) {
	int* row = (int*)calloc(size, sizeof(int));
	*(row + 0) = sign;
	int be = 0;
	int* characteristic = calculateCharacteristic(be + 127);

	int i, j;
	for (i = 1, j = 0; i < 9; i++, j++) {
		*(row + i) = *(characteristic + j);
	}

	float remainder = random - 1;
	int* mantissa = calcMantissa(remainder);

	for (i = 9, j = 0; i < 31; i++, j++) {
		*(row + i) = *(mantissa + j);
	}
	free(characteristic);
	free(mantissa);
	return row;
}

int* calculateCharacteristic(int number) {
	int* characteristic = (int*)calloc(8, sizeof(int));
	int i = 7;
	int remainder;
	while (i >= 0) {
		remainder = number % 2;
		*(characteristic + i) = remainder;
		i--;
		number /= 2;
	}
	return characteristic;
}

int* calcMantissa(float number) {
	int* mantissa = (int*)calloc(23, sizeof(int));
	int i = 0;
	float result = number * 2;
	while (result != 0 && i != 23) {
		*(mantissa + i) = (int)result;
		if (result >= 1) result--;
		i++;
		result *= 2;
	}
	return mantissa;
}

int findRowWithMostOnes(int** matrix, int rows, int cols) {
	int i, j;
	int currentOnesCounter = 0;
	int maxOnes = 0;
	int maxIndex = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (*(*(matrix + i) + j) == 1) {
				currentOnesCounter++;
			}
		}
		if (currentOnesCounter > maxOnes) {
			maxOnes = currentOnesCounter;
			maxIndex = i;
		}
		currentOnesCounter = 0;
	}
	return maxIndex;
}

void printRow(int** matrix, int row, int cols) {
	int i;
	for (i = 0; i < cols; i++) {
		printf("%d ", *(*(matrix + row) + i));
			}
	printf("\n\n");
}

void printMatrix(int** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}

void* freeMatrix(int** matrix, int rows) {
	int i;
	for (i = 0; i < rows; i++) {
		free(*(matrix + i));
	}
	free(matrix);
	return NULL;
}