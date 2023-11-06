#include "Header.h"

int main(void) {

	int inputOption;
	char* fileName = "clanovi.bin";

	do {

		printMenu();

		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1:
			addMember(fileName);
			break;
		case 2:
			readFile(fileName, -1);
			break;
		case 3:
			inputOption = exitProgram();
			break;
		default:
			puts("Ta operacija ne postoji!\n");
			break;
		}

	} while (inputOption != 3);

	return 0;
}