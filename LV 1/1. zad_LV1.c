#include <stdio.h>

int main() {
	int br10, br2, i = 7, ostatak;
	do {
		scanf("%d", &br10);
	} while (br10 < -128 || br10 > 127);

	int flag = 0;
	if (br10 > 0) { flag = 1; }
	else { br10 *= -1; }
	int polje[8];

	//pretvorba koja ide od kraja prema pocetku da bi se dobilo normalno polje a ne invertirano
	//to ima vise smisla jer moramo puno puta prolazit kroz polje kasnije pa ima vise smisla
	//pisat for petlje koje krecu od nule umijesto for petlji koje krecu od 7
	while (i>=0) {
		ostatak = br10 % 2;
		polje[i] = ostatak;
		i--;
		br10 = br10 / 2;
	}

	/* 1. korak
		br10 = 5
		ostatak = 1
		polje[0] = 1
		i se poveca za 1 dakle i = 1
		5/2 = 2 jt br10 = 2

		2. korak
		br10 = 2
		ostatak = 0
		polje[1] = 0
		i se poveca dakle i = 2
		2/2 = 1 br10 = 1

		3. korak
		br10 = 1
		ostatak = 1
		polje[2] = 1;
		i se poveca za 1 i = 3
		1/2 tj br10 = 0

		4. provjera br10 != 0 prekida da se nastavi dok i ne doðe do 7
	*/


	//mora bit flag da znamo jel pozitivno ili nije
	if (flag) {
		for (i = 0; i < 8; i++) {
			printf(" %d", polje[i]);
		}
	}
	else {

		for (i = 0; i < 8; i++) {
			printf(" %d", polje[i]);
		}
		printf(" - broj\n");

		//prvi komplement
		for (i = 0; i < 8; i++) {
			if (polje[i] == 0) {
				polje[i] = 1;
			}
			else if (polje[i] == 1) {
				polje[i] = 0;
			}
		}

		
		for (i = 0; i < 8; i++) {
			printf(" %d", polje[i]);
		}
		printf(" - prvi komplement\n");

		//Kreni od kraja prema poèetku i dodaj na svaku jedinicu 1 dakle 1+1=0
		//a kad dodes do nule samo stavi 1 dakle 1+0 = 1 i prekini petlju jer vise nema prijenosa.
		for (i = 7; i >= 0; i--) {
			if (polje[i] == 1) {
				polje[i] = 0;
			}
			else {
				polje[i] = 1;
				break;
			}
		}
		for (i = 0; i < 8; i++) {
			printf(" %d", polje[i]);
		}
		printf(" - drugi komplement\n");
	}
	
	return 0;
}