#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    float x, y, z;
}POINT;

int main(void) {

    const int pointAmount = 10;

    POINT* points = (POINT*)malloc(pointAmount * sizeof(POINT));
    int i;

    for (i = 0; i < pointAmount; i++) {
        scanf("%f%f%f", &(points + i)->x, &(points + i)->y, &(points + i)->z);
    }

    float max = (points + 0)->z;
    for (i = 0; i < pointAmount; i++) {
        if ((points + i)->z > max) {
            max = (points + i)->z;
        }
    }

    printf("REZULTATI:\n%.2f\n", max);
    free(points);
    return 0;
}