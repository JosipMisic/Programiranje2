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
		printf("Enter number in range 0 - 5: ");
		scanf("%d", number);
	} while (*number < 0 || *number > 5);
}

int* inputArray(int numAmountToTest) {
	int i;
	int* arrayToTest = (int*)malloc(numAmountToTest * sizeof(int));
	for (i = 0; i < numAmountToTest; i++) {
		do {
			printf("Enter %d number to find: ", i + 1);
			scanf("%d", &arrayToTest[i]);
		} while (arrayToTest[i] < 0 || arrayToTest[i] > 1000);
	}
	return arrayToTest;
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

int globalCounter;
int binarySearch(int* arrayToSearch, int sizeOfArray, int numberToFind) {
	globalCounter = 0;
	int lowerLimit = 0;
	int upperLimmit = sizeOfArray - 1;
	int middle = (lowerLimit + upperLimmit) / 2;

	while (lowerLimit <= upperLimmit) {
		middle = (lowerLimit + upperLimmit) / 2;
		globalCounter++;
		if (arrayToSearch[middle] == numberToFind) {
			return middle;
		}
		if (arrayToSearch[middle] < numberToFind) {
			lowerLimit = middle + 1;
		}
		if (arrayToSearch[middle] > numberToFind) {
			upperLimmit = middle - 1;
		}
	}

	return -1;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

int main() {

	char* fileName = "dat.txt";
	int arraySize = 500;
	int lowerLimit = 0;
	int upperLimit = 1000;
	generateNumberFile(fileName, arraySize, lowerLimit, upperLimit);

	int testArraySize;
	input(&testArraySize);
	int* numbersToFind = inputArray(testArraySize);

	int* arrayToSearch = readArrayFromFile(fileName, arraySize);

	printf("REZULTATI:\n");
	printf("Sekvencijalno:\n");

	int i, sequentialResult;
	int stepSumSequential = 0;
	for (i = 0; i < testArraySize; i++) {
		sequentialResult = sequentialSearch(arrayToSearch, arraySize, numbersToFind[i]);
		if (sequentialResult != -1) {
			printf("%d. Broj %d je pronadjen nakon %d koraka.\n", i + 1, numbersToFind[i], sequentialResult + 1);
			stepSumSequential += sequentialResult + 1;
		}
		else
			printf("%d. Broj %d nije pronadjen.\n", i + 1, numbersToFind[i]);
	}

	int binaryResult;
	int stepSumBinary = 0;

	bubbleSort(arrayToSearch, arraySize);

	printf("Binarno:\n");

	for (i = 0; i < testArraySize; i++) {
		binaryResult = binarySearch(arrayToSearch, arraySize, numbersToFind[i]);
		if (binaryResult != -1) {
			printf("%d. Broj %d je pronadjen nakon %d koraka.\n", i + 1, numbersToFind[i], globalCounter);
			stepSumBinary += globalCounter;
		}
		else
			printf("%d. Broj %d nije pronadjen.\n", i + 1, numbersToFind[i]);
	}
	

	printf("Srednji broj koraka za sekvencijalno pretrazivanje je: %.2f\n", (float)stepSumSequential / testArraySize);
	printf("Srednji broj koraka za binarno pretrazivanje je: %.2f", (float)stepSumBinary / testArraySize);
	
	free(numbersToFind);
	free(arrayToSearch);
	
	return 0;
}