#include "Header.h"

void readData(int* numberOfStudents, FILE* inFile) {
	fscanf(inFile, "%d", numberOfStudents);
}

void getData(char* data) {
	fscanf(stdin, "%s", data);
}

void writeStudentToFile(int idx, char* fName, char* lName, FILE* outFile) {
	fprintf(outFile, "Student broj:%d.\tIme: %s\t Prezime: %s\n", idx, fName, lName);
}

void writeData(int numberOfStudents, FILE* outFile) {
	char fName[128];
	char lName[128];
	int i = 0;
	for (i; i < numberOfStudents; i++) {
		getData(&fName);
		getData(&lName);
		writeStudentToFile(i, fName, lName, outFile);
	}
}