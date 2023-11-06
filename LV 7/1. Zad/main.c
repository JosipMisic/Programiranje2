#include "Header.h"

int main(void) {

	FILE* inFile = fopen("Dat.txt", "r");
	if (inFile == NULL) { printf("Greska u otvaranju Dat.txt.\n"); return 1; }

	int numberOfStudents;
	readData(&numberOfStudents, inFile);

	FILE* outFile = fopen("Studenti.txt", "w");
	if (outFile == NULL) { printf("Greska u otvaranju Studenti.txt.\n"); return 1; }

	writeData(numberOfStudents, outFile);
	
	fclose(inFile); fclose(outFile);

	return 0;
}
