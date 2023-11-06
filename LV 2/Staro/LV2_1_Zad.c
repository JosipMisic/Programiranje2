#include <stdio.h>

int main() {

	char* daysOfTheWeek[] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

	int day;
	do {
		printf("Enter day of the week: ");
		scanf("%d", &day);
	} while (day < 1 || day > 7);

	printf("The chosen day is %s.", *(daysOfTheWeek + day - 1));

	return 0;
}