#include "Header.h"

void unosDuljine(int* numberOfArticles) {
    do {
        scanf("%d", numberOfArticles);
    } while (numberOfArticles <= 0 || numberOfArticles > 60);
}

ARTICLE* kreiranjeArtikala(int numberOfArticles) {
    return (ARTICLE*)malloc(numberOfArticles * sizeof(ARTICLE));
}

void unosArtikla(ARTICLE* const articles, int numberOfArticles) {
    int i;
    for (i = 0; i < numberOfArticles; i++) {
        scanf("%s%d%f",
            (articles + i)->name,
            &(articles + i)->amount,
            &(articles + i)->price
        );
    }
}

ARTICLE* pretragaArtikla(const ARTICLE* const articles, int numberOfArticles) {
    int i;
    ARTICLE* max = (articles + 0);
    for (i = 0; i < numberOfArticles; i++) {
        if ((articles + i)->price > max->price) {
            max = articles + i;
        }
    }
    return max;
}

void ispisArtikla(ARTICLE* singleArticle) {
    printf("cijena: %.2f, kolicina: %d, ime: %s",
        singleArticle->price,
        singleArticle->amount,
        singleArticle->name
    );
}