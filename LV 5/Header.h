#ifndef HEADER_H
#define HEADER_H
const int lowerLimit = 3;
const int upperLimit = 25;
const int matrixLL = -1550;
const int matrixUL = 250;

short** zauzimanjeMatrice(int rows, int cols);
void popunjavanjeMatrice(short** matrix, int rows, int cols);
short najveciParniBroj(short** matrix, int rows, int cols);
void novaMatrica(short** matrix, int rows, int cols, short max);
void ispisMatrice(short** matrix, int rows, int cols);
void* brisanjeMatrice(short** matrix, int rows);

#endif // HEADER_H
