#include <stdio.h>

int isConsonant(char letter) {
	char vowel[] = "aeiouAEIOU";
	int i;
	for (i = 0; *(vowel + i) != '\0'; i++) {
		if (letter == *(vowel + i)) {
			return 0;
		}
	}
	return 1;
}

char* consCount(char* daysOfTheWeek[], int arraySize) {
	int i, j;
	int curConsCounter = 0, maxConsCounter = 0, maxConsIndex;
	for (i = 0; i < arraySize; i++) {
		for (j = 0; *(*(daysOfTheWeek + i) + j) != '\0'; j++) {
			if (isConsonant(daysOfTheWeek[i][j])) {
				curConsCounter++;
			}
		}
		if (curConsCounter > maxConsCounter) {
			maxConsCounter = curConsCounter;
			maxConsIndex = i;
		}
		curConsCounter = 0;
	}
	return *(daysOfTheWeek + maxConsIndex);
}

int main() {

	char* daysOfTheWeek[] = {
		"Monday", "Tuesday",
		"Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday"
	};

	printf("The day with the most consonants is %s.", consCount(daysOfTheWeek, 7));

	return 0;
}