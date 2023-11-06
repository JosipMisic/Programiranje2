#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DG -1.25
#define GG 5.75

void printMatrix(float** matrix, int rows, int cols);
float findMaxAboveMinorDiagonal(float** matrix, int rows, int cols);
float findMaxAboveMajorDiagonal(float** matrix, int rows, int cols);
void* freeMatrix(float** matrix, int rows);
void fillMatrix(float** matrix, int rows, int cols);

int main() {

	// isto kao i na prog1 unošenje velicine matrice ograniceno na neki interval
	int matrixSize;
	do {
		printf("Enter size of the matrix: ");
		scanf("%d", &matrixSize);
	} while (matrixSize < 2 || matrixSize > 8);

	// dinamicka alokacija polja ciji je svaki element pokazivac
	// svaki element ovog polja ce predstavljat jedan redak unutar matrice
	// dakle dobili smo ovako nešto [x,x,x] gdje svaki x predstavlja
	// pokazivac na float
	float** matrix = (float**)calloc(matrixSize, sizeof(float*));

	// Obilazimo polje koje smo gore stvorili i za svaki element stvaranmo novo polje
	// Veličina novog polja određena je brojem stupaca matrice. Dakle svaki x od gore
	// pretvaramo u zasebno polje. Možemo si to zamisliti kao polje u polju.
	// [x, x, x] smo imali gore. Sada to postaje [[0,0,0],[0,0,0],[0,0,0]]
	// zapravo smo dobili nul matricu jer calloc postavlja sve na nulu.
	int i, rows = matrixSize, cols = matrixSize;
	for (i = 0; i < rows; i++) {
		*(matrix + i) = (float*)calloc(cols, sizeof(float));
	}

	srand((unsigned)time(NULL));

	fillMatrix(matrix, rows, cols);

	printMatrix(matrix, rows, cols);

	float maxAboveMinorDiagonal = findMaxAboveMinorDiagonal(matrix, rows, cols);
	float maxAboveMajorDiagonal = findMaxAboveMajorDiagonal(matrix, rows, cols);
	printf("Max above the minor diagonal is %f.\n", maxAboveMinorDiagonal);
	printf("Max above the major diagonal is %f.\n", maxAboveMajorDiagonal);

	matrix = freeMatrix(matrix, rows);

	return 0;
}

void printMatrix(float** matrix, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("%f\t", *(*(matrix + i) + j));
		}
		printf("\n");
	}
}

float findMaxAboveMinorDiagonal(float** matrix, int rows, int cols) {
	int i, j;
	//dodavanje maksimumu vrijednosti iz naše matrice isto kao i
	// int max = matrix[i][j]
	float max = *(*(matrix + 0) + 0);

	// Obilazimo cijelu matricu isto kao i na programiranju 1
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			// Uvijet za elemente iznad sporedne diagonale isto prog1
			if (i + j < rows - 1) {
				// ukoliko je trenutni element veći od maksimuma
				// u maksimum treba spremiti vrijednost trenutnog elementa
				if (*(*(matrix + i) + j) > max) {
					max = *(*(matrix + i) + j);
				}
			}
		}
	}
	return max;
}

float findMaxAboveMajorDiagonal(float** matrix, int rows, int cols){
	int i, j;
	// Odabran element koji je sigurno iznad glavne diagonale.
	float max = *(*(matrix + 0) + cols - 1);

	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			// Uvijet za iznad glavne diagonale
			if (i < j) {
				// ukoliko je trenutni element veći od maksimuma
				// u maksimum treba spremiti vrijednost trenutnog elementa
				if (*(*(matrix + i) + j) > max) {
					max = *(*(matrix + i) + j);
				}
			}
		}
	}
	return max;
}

void* freeMatrix(float** matrix, int rows) {
	int i;
	// matricu moramo osloboditi jednako kako smo je i zauzeli
	// dakle prvo treba proći po svim redovima matrice i svako
	// polje treba osloboditi
	// dakle ovo [[0,0,0],[0,0,0],[0,0,0]] postaje [x,x,x]
	for (i = 0; i < rows; i++) {
		free(*(matrix + i));
	}
	// Nakon toga treba osloboditi veliko polje koje je sadržavalo
	// pokazivače na mala polja, dakle ovo [x,x,x] se briše
	// vraća se vrijednost NULL jer je dobro sve pokazivače koje ne
	// koristimo staviti na NULL vrijednost kako bi se kasnije izbjegle
	// greške u većim programima.
	free(matrix);
	return NULL;
}

void fillMatrix(float** matrix, int rows, int cols) {
	// **matrix predstavlja skroz vanjsko polje [[0,0,0],[0,0,0],[0,0,0]] dakle sve ovo.
	// *(matrix + 2) predstavlja unutrašnje polje s indeksom 2 dakle.
	// 				[[0,0,0],[0,0,0],[0,0,0]]
	// indexi tj i		0		1		2
	// univerzalno zapisano ako nam treba jedno od unutrašnjih polja
	// možemo mu pristupiti koristeći izraz *(matrix + i)

	// *(*(matrix + i) + j) predstavlja točno određeni element unutar naše matrice
	// *(*(matrix + i) + j) se još može zapisati kao matrix[i][j]

	// indexi unutarnjih polja tj j				  0 1 2   0	1 2   0 1 2
	// 											[[0,0,0],[0,0,0],[0,0,0]]
	// indexi vanjskih polja tj i					0		1		2

	// Dodavanje nasumicne vrijednosti svakom elementu matrice
	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			*(*(matrix + i) + j) = DG + (float)rand() / RAND_MAX * (GG - DG);
		}
	}
}
