#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>

void readData(int* numberOfStudents, FILE* inFile);

void getData(char* data);

void writeStudentToFile(int idx, char* fName, char* lName, FILE* outFile);

void writeData(int numberOfStudents, FILE* outFile);

#endif





