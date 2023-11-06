#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void readMatrixDimens(FILE* inFile, int* rows, int* cols);

FILE* openFile(char* fileName, char* mode);

float** allocateMatrix(int rows, int cols);

void inputMatrix(float** matrix, int rows, int cols);

void writeMatrix(FILE* outFile, float** matrix, int rows, int cols);


#endif





