#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int** allocateMatrix(int rows, int cols);
void fillMatrix(int** matrix, int rows, int cols);
int generateNumber();
int convertedToDec(int* binaryNumber, int binarySize);
void printMatrix(int** matrix, int rows, int cols);
double findAverage(int** matrix, int rows, int cols);
void* freeMatrix(int** matrix, int rows);

int main() {

	int rows, cols;
	do {
		printf("Enter the number of rows: ");
		scanf("%d", &rows);
	} while (rows < 2 || rows > 20);
	do {
		printf("Enter the number of cols: ");
		scanf("%d", &cols);
	} while (cols < 5 || cols > 25);

	//// Testing should be 5
	//int number[32] = { 
	//	0,0,0,0,0,0,0,0,
	//	0,0,0,0,0,0,0,0,
	//	0,0,0,0,0,0,0,0,
	//	0,0,0,0,0,1,0,1 };
	//// Should be -5
	//int number2[32] = {
	//	1,1,1,1,1,1,1,1,
	//	1,1,1,1,1,1,1,1,
	//	1,1,1,1,1,1,1,1,
	//	1,1,1,1,1,0,1,1
	//};
	//printf("%d", convertedToDec(number2, 32));

	int** matrix = allocateMatrix(rows, cols);

	srand((unsigned)time(NULL));

	fillMatrix(matrix, rows, cols);

	printMatrix(matrix, rows, cols);

	double averageOfMatrix = findAverage(matrix, rows, cols);
	printf("Average is %lf", averageOfMatrix);

	matrix = freeMatrix(matrix, rows);

	return 0;
}

int** allocateMatrix(int rows, int cols) {
	int** matrix = (int**)calloc(rows, sizeof(int*));

	int i;
	for (i = 0; i < rows; i++) {
		*(matrix + i) = (int*)calloc(cols, sizeof(int));
	}
	return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			*(*(matrix + i) + j) = generateNumber();
		}
	}
}

int generateNumber() {
	const int binarySize = 32, LOWERLIMIT = 0, UPPERLIMIT = 1;
	int i;
	int* binaryNumber = (int*)calloc(binarySize, sizeof(int));
	float random;
	for (i = 0; i < binarySize; i++) {
		random = LOWERLIMIT + (float)rand() / RAND_MAX * (UPPERLIMIT - LOWERLIMIT);
		if (random <= 0.5) {
			*(binaryNumber + i) = 0;
		}
		else {
			*(binaryNumber + i) = 1;
		}

	}
	int decNumber = convertedToDec(binaryNumber, binarySize);
	free(binaryNumber);
	return decNumber;
}

int convertedToDec(int* binaryNumber, int binarySize) {
	int i, flag = 0;
	if (*(binaryNumber + 0) == 1) {
		flag = 1; // zapamti predznak
		// binaryNumber is negative

		// prvi komplement
		for (i = 0; i < binarySize; i++) {
			if (*(binaryNumber + i) == 0) {
				*(binaryNumber + i) = 1;
			}
			else if (*(binaryNumber + i) == 1) {
				*(binaryNumber + i) = 0;
			}
		}

		// drugi komplement
		for (i = binarySize - 1; i >= 0; i--) {
			if (*(binaryNumber + i) == 1) {
				*(binaryNumber + i) = 0;
			}
			else {
				*(binaryNumber + i) = 1;
				break;
			}
		}
	}

	// pretvorba binarnog u dekadski
	int digit, decNumber = 0, power = binarySize - 1;
	for (i = 0; i < binarySize; i++) {
		digit = *(binaryNumber + i) * pow(2, power);
		decNumber += digit;
		power--;
	}

	if (flag == 1)
		return -decNumber;
	else
		return decNumber;
}

void printMatrix(int** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%d\t", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}

double findAverage(int** matrix, int rows, int cols) {
	int i, j;
	long long int sum = 0;
	int counter = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			sum += *(*(matrix + i) + j);
			counter++;
		}
	}
	return sum / (float)counter;
}

void* freeMatrix(int** matrix, int rows) {
	int i;
	for (i = 0; i < rows; i++) {
		free(*(matrix + i));
	}
	free(matrix);
	return NULL;
}