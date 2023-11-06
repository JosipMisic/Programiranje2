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

typedef struct movie {
	char name[128];
	int date, memberId;
}FILM;

void printMenu();
void addMember(char* fileName);
void inputMember(CLAN* member);
void readFile(char* fileName, int id);
int exitProgram();
int checkCondition(char* str);

void createMoviesFile(char* moviesFileName);
void rentMovie(char* membersFileName, char* moviesFileName);
void getMovieNumber(int* movieNumber);
void getMovieToRent(FILM* movie);
int checkForMember(char* memberFileName, FILM* movie);
int checkMemberRentStatus(char* moviesFileName, FILM* movie);
void registerRentedMovie(char* moviesFileName, FILM* movie);

#endif // !HEADER_H
