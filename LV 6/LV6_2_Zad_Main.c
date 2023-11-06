#include "Header.h"

int main(void)
{
    ARTICLE* articles, * max;

    int numberOfArticles;
    unosDuljine(&numberOfArticles);

    articles = kreiranjeArtikala(numberOfArticles);

    unosArtikla(articles, numberOfArticles);

    max = pretragaArtikla(articles, numberOfArticles);

    printf("REZULTATI:\n");
    ispisArtikla(max);
    
    free(articles);
    return 0;
}