#include "Header.h"

void printMenu() {
	printf("Pick your options: \n");
	printf("1- Dodavanje novih clanova u clanovi.bin\n");
	printf("2- Citanje iz datoteke clanovi.bin\n");
	printf("3- Zavrsetak programa.\n");
}

void addMember(char* fileName) {
	int memberCounter = 0;

	FILE* file = fopen(fileName, "rb+");
	if (file != NULL) {
		fread(&memberCounter, sizeof(int), 1, file);
	}
	else {
		file = fopen(fileName, "wb");
		fwrite(&memberCounter, sizeof(int), 1, file);
	}

	CLAN member;
	inputMember(&member);

	memberCounter++;
	rewind(file);
	fwrite(&memberCounter, sizeof(int), 1, file);

	fseek(file, 0, SEEK_END);
	fwrite(&member, sizeof(CLAN), 1, file);

	puts("\nMember added.\n");

	fclose(file);
}

void inputMember(CLAN* member) {
	printf("Enter member first name: ");
	scanf(" %[^\n]s", member->fName);

	printf("Enter member last name: ");
	scanf(" %[^\n]s", member->lName);

	printf("Enter member id: ");
	scanf("%d", &member->ID);
	getchar();

	printf("Enter memeber address: ");
	scanf(" %[^\n]s", member->address);

	printf("Enter member phone number: ");
	scanf(" %[^\n]s", member->phoneNumber); getchar();
}

void readFile(char* fileName, int id) {
	FILE* inFile = fopen(fileName, "rb");
	CLAN member;
	int memberCounter, i;
	if (inFile != NULL) {
		fread(&memberCounter, sizeof(int), 1, inFile);
		for (i = 0; i < memberCounter; i++) {
			fread(&member, sizeof(CLAN), 1, inFile);
			if (id == member.ID) {
				printf("\nName: %s %s\n", member.fName, member.lName);
				printf("ID: %d\nPhone num: %s\n", member.ID, member.phoneNumber);
				printf("Address: %s\n", member.address);
			}
			else if (id == -1) {
				printf("\nName: %s %s\n", member.fName, member.lName);
				printf("ID: %d\nPhone num: %s\n", member.ID, member.phoneNumber);
				printf("Address: %s\n", member.address);
			}
		}
		fclose(inFile);
	}
	puts("\n---- END OF FILE ----\n");
}

int exitProgram() {
	char str[3], c;
	int i = 0, counter = 0;
	puts("\nJeste li sigurni da zelite zavrsiti program?\n");
	do {
		printf("Unesi da/ne: ");
		fgets(str, 3, stdin);

		if (toupper(str[0]) == 'D' && toupper(str[1]) == 'A' && str[2] == '\0')
			exit(EXIT_SUCCESS);

	} while (checkCondition(str));
	return 1;
}

int checkCondition(char* str) {
	if (toupper(str[0]) == 'N' && toupper(str[1]) == 'E' && toupper(str[2]) == '\0') return 0;
	return 1;
}