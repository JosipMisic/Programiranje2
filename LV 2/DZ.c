#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//
//int main() {
//
//	char* daysOfTheWeek[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
//
//	int day;
//	do {
//		printf("Enter day of the week: ");
//		scanf("%d", &day);
//		if (day < 1 || day>7) {
//			printf("Krivo upisan broj\n");
//		}
//	} while (day < 1 || day > 7);
//
//	printf("The chosen day is %s.", *(daysOfTheWeek + day - 1));
//
//	return 0;
//}


#include <stdio.h>
#include <string.h>

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
			if (isConsonant(*(*(daysOfTheWeek + i) + j))) {
				curConsCounter++;
			}
		}
		if (curConsCounter > maxConsCounter) {
			maxConsCounter = curConsCounter;
			maxConsIndex = i;
		}
		curConsCounter = 0;
	}
	for (i = 0; i < maxConsIndex; i++) {
		return *(daysOfTheWeek + maxConsIndex);
	}
}

int main() {
	char* reverse;
	int i;
	char* daysOfTheWeek[] = {
		"Monday", "Tuesday",
		"Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday"
	};
	reverse = consCount(daysOfTheWeek, 7);
	printf("The day with the most consonants is %s.\n", consCount(daysOfTheWeek, 7));
	for (i = strlen(reverse); i >= 0; i--) {
		printf("%c", *(reverse + i));
	}

	return 0;
}