#include <iostream>
#include <iomanip>
using namespace std;

/*
Napisati program koji će omogučiti:

Unos 2D niza od 10 x 10 elemanata vodeći računa da su svi elementi dvocifreni (ukoliko unos nekog elementa ne zadovoljava uslov, 
ponavljati unos tog elementa dok se ne zadovolji uslov); Koristiti funkciju unos
Izvršiti transpoziciju niza tako što će se zamjeniti redovi i kolone - Koristiti funkciju transpose, a zatim na osnovu izmijenjenog 2D niza:
Izračunati aritmetičku sredinu svih prostih brojeva ispod sporedne dijagonale - Koristiti dvije funkcije: aritmeticka i prost_broj
(pozivati će se iz funkcije aritmeticka)
Napisati funkciju simpatican koja će provjeriti da li su brojevi iznad sporedne dijagonale simpatični*.
Obavezno koristiti navedene funkcije, a parametre i eventualne povratne vrijednosti definisati prema potrebi. 
U main() funkciji napisati testni program koji će omogućiti izvršenje svih funkcija navedenim redoslijedom.

[a][a][a][a][a]        [a][b][c][d][e]
[b][b][b][b][b]        [a][b][c][d][e]
[c][c][c][c][c]  --->  [a][b][c][d][e]
[d][d][d][d][d]        [a][b][c][d][e]
[e][e][e][e][e]        [a][b][c][d][e]
Pomoć: Broj je simpatičan ukoliko je zbir cifara njegovog kvadrata jednak kvadratu zbira njegovih cifara.
Broj 21 je simpatičan jer je s(441) = s(21) * s(21) pri čemu je s(n) zbir cifara prirodnog broja n.
*/

const int vel = 10;

void unos (int niz[][vel]) {

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			do {

				niz[i][j] = rand () % 100 + 10;

			} while (niz[i][j] > 100 && niz[i][j] < 10);

		}
	}

}

void transpose (int niz[][vel]) {

	int temp;

	for (int i = 0; i < vel; i++) {
		for (int j = i; j < vel; j++) {

			temp = niz[i][j]; 
			niz[i][j] = niz[j][i]; 
			niz[j][i] = temp;					  
		
		}
	}

}

void ispis (int niz[][vel]) {

	for (int i = 0; i < vel; i++) {
		cout << endl;
		for (int j = 0; j < vel; j++) {

			cout <<setw(10)<<niz[i][j];

		}
	}
}

bool prostBroj (int broj) {

	for (int i = 2; i < broj / 2; i++) {

		if (broj % i == 0)
			return false;
		else
			return true;

	}

}

float aritmeticka (int niz[][vel]) {

	int suma = 0.0, brojac = 0.0;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			if (i + j > vel - 1) {

				if (prostBroj (niz[i][j])) {

					suma += niz[i][j];
					brojac++;

				}
			}
		}
	}
	return suma / brojac;
}

int main () {

	int niz[vel][vel];

	unos (niz);

	cout <<endl<< "Ispis nakon unosa" << endl;
	ispis (niz);

	cout <<endl<< endl << "Ispis nakon transpozicije" << endl;
	transpose (niz);

	ispis (niz);

	cout <<endl<<endl<< "Aritmeticka sredina prostih clanova ispod sporedne dijagonale je: " << aritmeticka (niz) << endl;

	system ("pause>0");
	return 0;
}
