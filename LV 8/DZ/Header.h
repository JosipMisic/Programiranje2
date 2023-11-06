#ifndef HEADER_H
#define HEADER_H

typedef struct student {
	char ime[20];
	char prezime[20];
	char adresa[50];
}STUDENT;


int kreiranjeDatoteke(FILE*);
void dodavanje(FILE*, int);
void dodavanje(FILE*, FILE*);


#endif // HEADER_H