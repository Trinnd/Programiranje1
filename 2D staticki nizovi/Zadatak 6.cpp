/*/////////////////////////////////////////////ASAD TABAK/////////////////////////////////////////////////////////////////////
Dat je 2D niz dimenzija 8 x 8. Omogućiti korisniku unos cjelobrojnih elemenata 2D niza tako da se u svaki neparni red
unesu parni brojevi a svaki parni red neparni broj. Napraviti funkciju koja pronalazi kolonu sa najmanjim prosjekom elemenata.
U istoj funkciji ispisati index pronađene kolone, a u main funkciji sve elemente te kolone.
*/

#include <iostream>
#include <iomanip>

using namespace std;
const int vel = 3;

bool provjera (int, int);
int prosjek (int[][vel]);


int main () {

	int niz[vel][vel];


	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			do {
				cout << "[" << i << "]" << "[" << j << "]" << endl;
				cin >> niz[i][j];
				//niz[i][j] = rand () % 100 + 1;

			} while (!provjera (i, niz[i][j]));

		}
	}

	for (int i = 0; i < vel; i++) {
		cout << endl;
		for (int j = 0; j < vel; j++) {

			cout <<setw(3)<< niz[i][j];
			
		}
	}
	int kol = prosjek (niz);

	cout << endl << "Elementi kolone sa najmanjim prosjekom" << endl;

	for (int i = 0; i < vel; i++) {

		cout << niz[i][kol];

	}
	
	system ("pause>0");

	return 0;
}

bool provjera (int red, int broj) {

	return(red % 2 == 0 && broj % 2 != 0 || red % 2 != 0 && broj % 2 == 0);

}

int prosjek (int niz[][vel]) {

	float prosjek[vel] = { 0 };
	float tempProsjek[vel];
	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; i++) {

			tempProsjek[i] += niz[i][j];
			tempProsjek[i] /= vel;

			
		}
		prosjek[i] = tempProsjek[i];
	}

	int najmanji = 0;

	for (int i = 0; i < vel; i++) {

		if (prosjek[i] < prosjek[najmanji]) {

			najmanji = i;

		}

	}

	cout << "kolona sa najmanjim prosjekom je: " << najmanji << endl;

	return najmanji;

}
