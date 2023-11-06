#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    float x, y;
}POINT;

typedef struct triangle {
    struct point *p1, *p2, *p3;
}TRIANGLE;

float extent(float a, float b, float c) {
    return a + b + c;
}

float dist(float x1, float y1, float x2, float y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main(void) {

    int n, m, i;
    do {
        scanf("%d", &m);
    } while (m < 3 || m >30);
    do {
        scanf("%d", &n);
    } while (n < 1 || n> 11);
    
    POINT* points = (POINT*)malloc(m * sizeof(POINT));
    TRIANGLE* triangles = (TRIANGLE*)malloc(n * sizeof(TRIANGLE));

    for (i = 0; i < m; i++) {
        scanf("%f%f", &points[i].x, &points[i].y);
    }

    int ind1, ind2, ind3;
    for (i = 0; i < n; i++) {
        scanf("%d%d%d", &ind1, &ind2, &ind3);
        triangles[i].p1 = &points[ind1];
        triangles[i].p2 = &points[ind2];
        triangles[i].p3 = &points[ind3];
    }

    float current = 0;
    float max = 0;
    int maxIndex;

    for (i = 0; i < n; i++) {
        current = 0;
        current += dist(triangles[i].p1->x, triangles[i].p1->y, triangles[i].p2->x, triangles[i].p2->y);
        current += dist(triangles[i].p2->x, triangles[i].p2->y, triangles[i].p3->x, triangles[i].p3->y);
        current += dist(triangles[i].p3->x, triangles[i].p3->y, triangles[i].p1->x, triangles[i].p1->y);
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