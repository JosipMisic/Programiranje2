#include <stdio.h>
#include <string.h>
#define MAX_AMOUNT 15

typedef struct date {
	int day, month, year;
}DATE;

typedef struct employee {
	char name[128];
	long idNumber;
	float paycheck;
	struct date birthDay;
}EMPLOYEE;

int main() {

	int n;
	do {
		scanf("%d", &n); getwchar();
	} while (n < 1 || n >= 16);
	
	EMPLOYEE employees[MAX_AMOUNT];

	int i;
	for (i = 0; i < n; i++) {
		printf("enter\n");
		fgets(employees[i].name, 128, stdin);
		//employees[i].name[strlen(employees[i].name) - 1] = '\0';
		scanf("%ld", &employees[i].idNumber); getchar();
		scanf("%f", &employees[i].paycheck); getchar();
		scanf("%d%d%d", &employees[i].birthDay.day, &employees[i].birthDay.month, &employees[i].birthDay.year); getchar();
	}

	EMPLOYEE bestPaid = employees[0];

	for (i = 0; i < n; i++) {
		if (employees[i].paycheck > bestPaid.paycheck) {
			bestPaid = employees[i];
		}
	}

	fputs(bestPaid.name, stdout);
	printf("%ld\t", bestPaid.idNumber);
	printf("%f\t", bestPaid.paycheck);
	printf("%d.%d.%d.\t", bestPaid.birthDay.day, bestPaid.birthDay.month, bestPaid.birthDay.year);

	return 0;
}