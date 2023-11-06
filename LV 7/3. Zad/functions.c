#include "Header.h"

FILE* openFile(char* fileName, char* mode) {
	FILE* file = fopen(fileName, mode);
	if (file == NULL) { printf("Greska pri rukovanju s %s.\n", fileName); exit(EXIT_FAILURE); }
	return file;
}

void copyData(FILE* firstFile, FILE* secondFile) {
	char c;
	while ((c = fgetc(firstFile)) != EOF) {
		fputc(toupper(c), secondFile);
	}
}