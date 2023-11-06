#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct article {
	char name[30];
	int amount;
	float price;
}ARTICLE;

void unosDuljine(int* numberOfArticles);
ARTICLE* kreiranjeArtikala(int numberOfArticles);
void unosArtikla(ARTICLE* const articles, int numberOfArticles);
ARTICLE* pretragaArtikla(const ARTICLE* const articles, int numberOfArticles);
void ispisArtikla(ARTICLE* singleArticle);

#endif // !HEADER_H
