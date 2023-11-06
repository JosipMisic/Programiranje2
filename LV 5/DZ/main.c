#include "Header.h"

int main() {

	srand((unsigned)time(NULL));

	int redovi, stupci;
	unos(&redovi, &stupci);

	float** matrica = alokacijaMatrice(redovi, stupci);

	popunjavanjeMatrice(matrica, redovi, stupci);
	transformiranjeMatrice(matrica, redovi, stupci);

	ispisMatrice(matrica, redovi, stupci);

	matrica = ispisMatrice(matrica, redovi);

	return 0;
}