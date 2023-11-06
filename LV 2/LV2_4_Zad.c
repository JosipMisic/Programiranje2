#include <stdio.h>
#include <string.h>

char* findBestAverageOfMonthName(char*[], int);
void printMonth(char*);

int main() {

	const int numberOfMonths = 12;
	char* monthsOfTheYear[] = {
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};

	char* monthWithBestAverage = findBestAverageOfMonthName(monthsOfTheYear, numberOfMonths);
	printMonth(monthWithBestAverage);

	return 0;
}

char* findBestAverageOfMonthName(char* months[], int numberOfMonths) {
	int i, j;
	int sumOfCharacters = 0, numberOfCharacters = 0;
	float currentAverage = 0, maxAverage = 0;
	int indexOfBestMonth;

	for (i = 0; i < numberOfMonths; i++) {
		for (j = 0; *(*(months + i) + j) != '\0'; j++) {
			sumOfCharacters += *(*(months + i) + j);
			numberOfCharacters++;
		}

		currentAverage = (float)sumOfCharacters / numberOfCharacters;
		numberOfCharacters = 0;
		sumOfCharacters = 0;

		if (currentAverage > maxAverage) {
			maxAverage = currentAverage;
			indexOfBestMonth = i;
		}
	}

	return *(months + indexOfBestMonth);
}

void printMonth(char* month) {
	int i;
	int length = strlen(month) - 1;
	for (i = length; i >= 0; i--) {
		printf("%c", *(month + i));
	}
}
