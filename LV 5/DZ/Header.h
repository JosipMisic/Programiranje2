#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void unos(int* redovi, int* stupci);

float** alokacijaMatrice(int redovi, int stupci);

void popunjavanjeMatrice(float** matrica, int redovi, int stupci);

float nadiMax(float* polje, int n);

void transformacijaMatrice(float** matrica, int redovi, int stupci);

void* oslobadanjeMatrice(float** matrica, int redovi);

void ispisMatrice(float** matrica, int redovi, int stupci);

#endif // !1
