#include "Header.h"

int main(void) {

	int inputOption;
	char* membersFileName = "clanovi.bin";
	char* moviesFileName = "posudbe.bin";

	do {

		printMenu();

		scanf("%d", &inputOption); getchar();

		switch (inputOption) {

		case 1:
			addMember(membersFileName);
			break;
		case 2:
			readFile(membersFileName, -1);
			break;
		case 3:
			rentMovie(membersFileName, moviesFileName);
			break;
		case 4:
			inputOption = exitProgram();
			break;
		default:
			puts("Ta operacija ne postoji!\n");
			break;
		}

	} while (inputOption != 4);

	return 0;
}