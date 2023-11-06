#include "Header.h"

int main(void) {

    int n, m, i;
    unosDuljine(&m, &n);

    POINT* points = zauzimanjeTocaka(m);
    TRIANGLE* triangles = zauzimanjeTrokutova(n);
	popunjavanjeKoordinata(points, m);
    odabirVrha(triangles, points, n, m);
	
    float current = 0;
    float max = 0;
    int maxIndex;

    for (i = 0; i < n; i++) {
        current = opsegTrokuta(triangles + i);
        if (current > max) {
            max = current;
            maxIndex = i;
        }
    }

    printf("Trokut %d ima opseg %.2f\n", maxIndex, max);
    free(points);
    free(triangles);
    return 0;
}