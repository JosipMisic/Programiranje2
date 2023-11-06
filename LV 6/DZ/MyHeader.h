#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct putovanje {
	int odrediste;
	float cijena;
	int brSlobodnihMjesta;
}PUTOVANJE;

void unosBrojaPutovanja(int* brojPutovanja);
PUTOVANJE* alokacijaPutovanja(int brojPutovanja);
PUTOVANJE* unosPutovanja(PUTOVANJE* const putovanja, int brojPutovanja);
void ispisPutovanja(PUTOVANJE* jednoPutovanje);

#endif // !HEADER_H