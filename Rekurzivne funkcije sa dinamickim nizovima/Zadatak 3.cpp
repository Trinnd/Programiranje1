#include <iostream>
#include <iomanip>
using namespace std;

/*
Napišite program koji će omogućiti kreiranje dinamičke matrice (o veličini matrice odlučuje korisnik) cijelih brojeva, 
te uz pomoć rekurzivnih funkcija omogućiti:
• unos elemenata,
• ispis elemenata,
• izračunati sumu svih elemenata matrice,
• sumu pozitivnih elemenata matrice,
• sumu elemenata matrice s parnim indeksima.
*/

void unos (int** pok, int red, int kol, int start, int brojac) {

	if (red < 0)
		return;

	if (start == 0) {

		pok[red] = new int[kol];
		start = 1;

	}

	if (kol > -1) {

		cout << "[" << red << "] [" << kol << "]" << endl;
		//cin >> pok[red][kol];
		pok[red][kol] = rand () % 100 + (-50);
		kol--;
		brojac++;
	}
	else {

		kol = brojac-1;
		brojac = 0;
		red--;
		pok[red] = new int[kol];
	}

	unos (pok, red, kol, start, brojac);

}

void ispis (int** pok, int red, int kol, int brojac) {

	if (red < 0)
		return;

	if (kol > -1) {

		cout <<"  "<< pok[red][kol];
		kol--;
		brojac++;

	}
	else {

		kol = brojac - 1;
		brojac = 0;
		red--;
		cout << endl;
	}
	ispis (pok, red, kol, brojac);
}

int suma (int** pok, int red, int kol, int brojac) {

	if (red < 0)
		return 0;

	if (kol > 0) {

		kol--;
		brojac++;
		return pok[red][kol] + suma (pok, red, kol, brojac);
	}
	else {

		kol = brojac;
		brojac = 0;
		red--;
		if (red >= 0)
			return suma (pok, red, kol, brojac);
	}

}

int poz (int** pok, int red, int kol, int brojac) {

	if (red < 0)
		return 0;


		if (kol > 0) {

			kol--;
			brojac++;

			if (pok[red][kol] > 0)
				return pok[red][kol] + poz (pok, red, kol, brojac);
			else
				poz (pok, red, kol, brojac);
		}
		else {

			kol = brojac;
			brojac = 0;
			red--;
			if (red >= 0)
				return poz (pok, red, kol, brojac);

		}

}

int pSuma (int** pok, int red, int kol, int brojac) {

	if (red < 0)
		return 0;

	if (kol > 0) {

		kol--;
		brojac++;
		if (red % 2 == 0 && kol % 2 == 0)
			return pok[red][kol] + pSuma (pok, red, kol, brojac);
		pSuma (pok, red, kol, brojac);
	}
	else {

		kol = brojac;
		brojac = 0;
		red--;
		if (red > 0)
			pSuma (pok, red, kol, brojac);

	}

}

void dealoc (int**& pok, int red, int kol) {

	if (red < 0)
		return;

	if (red > 0) {

		red--;
		delete[] pok[kol];
	}
	else if (red == 0) {

		delete[] pok;
		pok = nullptr;
		red--;
	}

	dealoc (pok, red, kol);
	

}

int main () {

	int red = 0, kol = 0, start = 0, brojac = 0;

	cout << "Unesite broj redova dinamicke matrice" << endl;
    cin >> red;

	cout << "Unesite broj kolona dinamicke matrice" << endl;
	cin >> kol;

	int **pok = new int*[red];

	unos (pok, red-1, kol-1, start, brojac);
	ispis (pok, red-1, kol-1, brojac);

	cout << "Suma svih elemenata matrice je: " << suma (pok, red - 1, kol, brojac)<<endl;
	cout << "Suma pozitivnih elemenata matrice je: " << poz (pok, red-1, kol, brojac)<<endl;
	cout << "Suma elemenata sa parnim indeksom je: " << pSuma (pok, red - 1, kol, brojac) << endl;

	dealoc (pok, red, kol);

	/*for (int i = 0; i < red; i++)
		delete[]pok[i];

	delete pok;

	pok = nullptr;*/

	return 0;
	system ("pause>0");

}
