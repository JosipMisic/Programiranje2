#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main() {
	FILE* fp1 = NULL;
	FILE* fp2 = NULL;
	citanje(fp1);
	brojac(fp1, fp2);

	return 0;
}