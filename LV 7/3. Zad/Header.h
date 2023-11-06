#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

FILE* openFile(char* fileName, char* mode);

void copyData(FILE* firstFile, FILE* secondFile);

#endif





