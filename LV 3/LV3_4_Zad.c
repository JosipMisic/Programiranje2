#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_AMOUNT 20
#define ADDRESS_LENGTH 128

int main(void) {

	int numberOfApartments;
	do {
		printf("Enter the number of apartments.\n");
		scanf("%d", &numberOfApartments); getchar();
	} while (numberOfApartments < 2 || numberOfApartments > 20);

	struct apartment {
		float area;
		float price;
		char address[ADDRESS_LENGTH];
		char energyRating;
		char acUnit;
	};

	struct apartment apartments[MAX_AMOUNT];

	for (int i = 0; i < numberOfApartments; i++) {

		printf("Enter apartment address.\n");
		fgets(apartments[i].address, ADDRESS_LENGTH, stdin);
		apartments[i].address[strlen(apartments[i].address) - 1] = '\0';

		printf("Enter apartment price.\n");
		scanf("%f", &apartments[i].price); getchar();

		printf("Enter apartment area.\n");
		scanf("%f", &apartments[i].area); getchar();

		printf("Enter energy rating.\n");
		apartments[i].energyRating = getchar(); getchar();

		printf("Is there an AC Unit? 1 -> Yes, 0 -> No.\n");
		scanf("%c", &apartments[i].acUnit); getchar();

		puts("\n");
	}

	printf("REZULTATI:\n");
	
	int flag = 0;
	float borderValue;
	for (int i = 0; i < numberOfApartments; i++) {
		borderValue = apartments[i].price / apartments[i].area;
		if ((borderValue < 900 || borderValue > 1000) && apartments[i].acUnit == 0) {
			printf("%s, %.2f\n", apartments[i].address, apartments[i].price);
			flag = 1;
		}
	}
	
	if (flag == 0){
	    printf("Niti jedan stan ne odgovara kriterijima.\n");
	}

	return 0;
}