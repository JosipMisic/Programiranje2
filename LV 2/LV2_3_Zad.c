#include <stdio.h>

int main() {

	char* monthsOfTheYear[] = {
		"January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December"
	};


	int month;
	do {
		scanf("%d", &month);
		if (month < 1 || month > 12) {
			printf("Krivo uneseni broj za mjesec.\n");
		}
	} while (month < 1 || month > 12);

	printf("The chosen month is %s.", *(monthsOfTheYear + month - 1));

	return 0;
}