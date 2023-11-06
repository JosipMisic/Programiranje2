#include <stdio.h>
#include <stdlib.h>

void generateNumberFile(char* fileName, int numberAmount, int lowerLimit, int upperLimit) {
	FILE* outFile = fopen(fileName, "w");
	int i;
	for (i = 0; i < numberAmount; i++) {
		int generatedNumber = lowerLimit + (float)rand() / RAND_MAX * (upperLimit - lowerLimit);
		fprintf(outFile, "%d\t", generatedNumber);
	}
	fclose(outFile);
}

void input(int* number) {
	do {
		scanf("%d", number);
	} while (*number < 0 || *number > 1000);
}

int* readArrayFromFile(char* fileName, int numberAmount) {
	FILE* inFile = fopen(fileName, "r");
	if (inFile == NULL) exit(EXIT_FAILURE);

	int* numbers = (int*)malloc(numberAmount * sizeof(int));

	int i;
	for (i = 0; i < numberAmount; i++) {
		fscanf(inFile, "%d", &numbers[i]);
	}

	fclose(inFile);

	return numbers;
}

int sequentialSearch(int* arrayToSearch, int numberAmount, int numberToFind) {
	int i;
	for (i = 0; i < numberAmount; i++) {
		if (arrayToSearch[i] == numberToFind) {
			return i;
		}
	}
	return -1;
}

int main() {

	char* fileName = "dat.txt";
	int numberAmount = 500;
	int lowerLimit = 0;
	int upperLimit = 1000;
	generateNumberFile(fileName, numberAmount, lowerLimit, upperLimit);

	int numberToFind;
	input(&numberToFind);

	int* arrayToSearch = readArrayFromFile(fileName, numberAmount);

	int result = sequentialSearch(arrayToSearch, numberAmount, numberToFind);
	if (result != -1)
		printf("Broj %d je pronadjen nakon %d koraka na indeksu %d.\n", numberToFind, result + 1, result);
	else
		printf("Broj %d nije pronadjen.\n", numberToFind);

	free(arrayToSearch);
	return 0;
}