#include <stdio.h>
#include <math.h>

int main() {
	int i, polje[8], potencija = 7, znamenka, sum=0;
	for(i=0; i<8;i++){
		do{
			scanf("%d", &polje[i]);
		} while (polje[i] < 0 || polje[i] > 1);
	}
	for(i=0;i<8;i++){
		znamenka = polje[i] * pow(2, potencija);
		sum += znamenka;
		potencija--;
	}
	printf("%d", sum);

	
	return 0;
}