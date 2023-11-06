#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
	float x, y;
}POINT;

typedef struct triangle {
	struct point* p1, * p2, * p3;
}TRIANGLE;

void unosDuljine(int* m, int* n);
float duljinaStranice(float x1, float y1, float x2, float y2);
POINT* zauzimanjeTocaka(int brojTocaka);
TRIANGLE* zauzimanjeTrokutova(int brojTrokuta);
void popunjavanjeKoordinata(POINT* const points, int numberOfPoints);
void odabirVrha(
	TRIANGLE* const triangles,
	POINT* const points,
	int numberOfTriangles,
	int numberOfPoints
);
float opsegTrokuta(const TRIANGLE* const triangle);

#endif // !HEADER_H
