#include <stdio.h>
#include <stdlib.h>

typedef struct article {
    char name[30];
    int amount;
    float price;
}ARTICLE;

int main(void)
{
    ARTICLE *articles, *max;

    int numberOfArticles;
    do {
        scanf("%d", &numberOfArticles);
    } while (numberOfArticles < 1 || numberOfArticles > 50);

    articles = (ARTICLE*)malloc(numberOfArticles * sizeof(ARTICLE));

    max = articles + 0;

    int i;
    for (i = 0; i < numberOfArticles; i++) {
        scanf("%s%d%f", (articles + i)->name, &(articles + i)->amount, &(articles + i)->price);
        if ((articles + i)->price > max->price) {
            max = articles + i;
        }
    }

    printf("REZULTATI:\n");
    printf("cijena: %.2f, kolicina: %d, ime: %s", max->price, max->amount, max->name);
    free(articles);
    return 0;
}