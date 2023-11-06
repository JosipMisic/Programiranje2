#include "Header.h"

void unosDuljine(int* m, int* n) {
    do {
        scanf("%d", m);
    } while (*m <= 4 || *m > 100);
    do {
        scanf("%d", n);
    } while (*n < 3 || *n >= 16);
}

float duljinaStranice(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

POINT* zauzimanjeTocaka(int brojTocaka) {
    return (POINT*)malloc(brojTocaka * sizeof(POINT));
}

TRIANGLE* zauzimanjeTrokutova(int brojTrokuta) {
    return (TRIANGLE*)malloc(brojTrokuta * sizeof(TRIANGLE));
}

void popunjavanjeKoordinata(POINT* const points, int numberOfPoints) {
    int i;
    for (i = 0; i < numberOfPoints; i++) {
        (points + i)->x = 0 + (float)rand() / RAND_MAX * (numberOfPoints - 0);
        (points + i)->y = 0 + (float)rand() / RAND_MAX * (numberOfPoints - 0);
    }
}

void odabirVrha(
    TRIANGLE* const triangles,
    POINT* const points,
    int numberOfTriangles,
    int numberOfPoints
) {
    int ind1, ind2, ind3, i;
    for (i = 0; i < numberOfTriangles; i++) {
        ind1 = 0 + (float)rand() / RAND_MAX * (numberOfPoints - 0);
        ind2 = 0 + (float)rand() / RAND_MAX * (numberOfPoints - 0);
        ind3 = 0 + (float)rand() / RAND_MAX * (numberOfPoints - 0);
        (triangles + i)->p1 = (points + 0) + ind1;
        (triangles + i)->p2 = points + ind2;
        (triangles + i)->p3 = points + ind3;
    }
}

float opsegTrokuta(const TRIANGLE* const triangle) {
    float opseg = 0;
    opseg += duljinaStranice(triangle->p1->x, triangle->p1->y, triangle->p2->x, triangle->p2->y);
    opseg += duljinaStranice(triangle->p2->x, triangle->p2->y, triangle->p3->x, triangle->p3->y);
    opseg += duljinaStranice(triangle->p3->x, triangle->p3->y, triangle->p1->x, triangle->p1->y);
    return opseg;
}