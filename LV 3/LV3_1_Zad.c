#include <stdio.h> // standard input output
#include <math.h>

typedef struct kompleksni {
	float re, im;
} KOMPLEKSNI;

typedef struct kompleksni KOMPLEKSNI;

int main() {

	KOMPLEKSNI br1, br2;
	KOMPLEKSNI rez;

	printf("Enter the real component of complex 1. complex number: ");
	scanf("%f", &br1.re);
	printf("Enter the imaginary component of complex 1. complex number: ");
	scanf("%f", &br1.im);

	printf("Enter the real component of complex 2. complex number: ");
	scanf("%f", &br2.re);
	printf("Enter the imaginary component of complex 2. complex number: ");
	scanf("%f", &br2.im);

	printf("REZULTATI:\n");

	// Zbrajanje
	rez.re = br1.re + br2.re;
	rez.im = br1.im + br2.im;
	if (rez.im > 0) {
		printf("%f + %fi", rez.re, rez.im);
	}
	else {
		printf("%f - %fi", rez.re, rez.im);
	}

	// Oduzimanje
	rez.re = br1.re - br2.re;
	rez.im = br1.im - br2.im;
	if (rez.im > 0) {
		printf("%f + %fi", rez.re, rez.im);
	}
	else {
		printf("%f - %fi", rez.re, rez.im);
	}
	
	// Mnozenje
	rez.re = br1.re * br2.re - br1.im * br2.im;
	rez.im = br1.re * br2.im + br1.im * br2.re;
	if (rez.im > 0) {
		printf("%f + %fi", rez.re, rez.im);
	}
	else {
		printf("%f - %fi", rez.re, rez.im);
	}
	

	// Dijljenje
	float c2 = br2.re * br2.re;
	float d2 = br2.im * br2.im;
	rez.re = (br1.re * br2.re + br1.im * br2.im) / (c2 + d2);
	rez.im = (br1.im * br2.re - br1.re * br2.im) / (c2 + d2);
	if (rez.im > 0) {
		printf("%f + %fi", rez.re, rez.im);
	}
	else {
		printf("%f - %fi", rez.re, rez.im);
	}

	float moduleBr1 = sqrt(br1.re * br1.re + br1.im * br1.im);
	float moduleBr2 = sqrt(br2.re * br2.re + br2.im  * br2.im);

	printf("%f", moduleBr1);
	printf("%f", moduleBr2);

	return 0;
}