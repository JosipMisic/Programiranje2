#include "Header.h"

int main(void) {
	FILE* firstFile = openFile("Prva.txt", "r");

	FILE* secondFile = openFile("Druga.txt", "w");

	copyData(firstFile, secondFile);

	fclose(firstFile); fclose(secondFile);

	return 0;
}