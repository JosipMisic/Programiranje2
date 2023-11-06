#include <stdio.h>

void selectionSort(int* arrayToSort, int sizeOfArray);
void print(int* array, int arraySize);
void swap(int* firstValue, int* secondValue);

int main() {

	int arrayToSort[] = { 100,11,12,86,54,2,5,0,12 };
	int arraySize = sizeof(arrayToSort) / sizeof(arrayToSort[0]);

	print(arrayToSort, arraySize);

	selectionSort(arrayToSort, arraySize);

	print(arrayToSort, arraySize);
	return 0;
}

void print(int* array, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		printf("%f\n", array[i]);
	}
	printf("\n");
}

void swap(int* firstValue, int* secondValue) {
	int temp = *firstValue;
	*firstValue = *secondValue;
	*secondValue = temp;
}

void selectionSort(int* arrayToSort, int arraySize) {
	int min;
	for (int i = 0; i < arraySize - 1; i++) {
		min = i;
		for (int j = i + 1; j < arraySize; j++) {
			if (arrayToSort[j] < arrayToSort[min]) {
				min = j;
			}
		}
		swap(&arrayToSort[min], &arrayToSort[i]);
	}
}