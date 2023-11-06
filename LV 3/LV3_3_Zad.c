#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define lowerLimit -2147483647
#define upperLimit 2147483647
#define MAX_AMOUNT 40

typedef struct cijeli_broj {
	long uneseni_broj;
	int broj_znamenaka;
}CIJELI_BROJ;

long int genPSNumber() {
	return rand() % upperLimit + lowerLimit;
}

int countDigits(long int number) {
	int counter = 0;
	while (number != 0) {
		counter++;
		number /= 10;
	}
	return counter;
}

int main() {

	srand((unsigned)time(NULL));
	
	CIJELI_BROJ numbers[MAX_AMOUNT];

	int i;
	for (i = 0; i < MAX_AMOUNT; i++) {
		numbers[i].uneseni_broj = genPSNumber();
		printf("%ld\n", genPSNumber());
		numbers[i].broj_znamenaka = countDigits(numbers[i].uneseni_broj);
	}

	CIJELI_BROJ numberWithMaxDigits = numbers[0];
	CIJELI_BROJ numberWithMinDigits = numbers[0];

	for (i = 0; i < MAX_AMOUNT; i++) {
		if (numbers[i].broj_znamenaka > numberWithMaxDigits.broj_znamenaka) {
			numberWithMaxDigits = numbers[i];
		}
		if (numbers[i].broj_znamenaka < numberWithMinDigits.broj_znamenaka) {
			numberWithMinDigits = numbers[i];
		}
	}

	printf("%ld\t", numberWithMaxDigits.uneseni_broj);
	printf("%d\t\n", numberWithMaxDigits.broj_znamenaka);
	
	printf("%ld\t", numberWithMinDigits.uneseni_broj);
	printf("%d\t\n", numberWithMinDigits.broj_znamenaka);

	return 0;
}