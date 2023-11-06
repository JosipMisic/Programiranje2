#ifndef HEADER_H
#define HEADER_H

#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>

typedef struct memberInfo {
	char lName[32];
	char fName[32];
	int ID;
	char address[128];
	char phoneNumber[16];
}CLAN;

void printMenu();
void addMember(char* fileName);
void inputMember(CLAN* member);
void readFile(char* fileName);
int exitProgram();
int checkCondition(char* str);

#endif // !HEADER_H
