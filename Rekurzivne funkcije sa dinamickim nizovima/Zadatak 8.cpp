#include <iostream>
#include <iomanip>
using namespace std;

/*
Napišite program koji će omogućiti kreiranje matrice 3x3 cijelih brojeva, te uz pomoć rekurzivnih funkcija omogućiti:
• unos elemenata,
• ispis elemenata,
• izračunati sumu svih elemenata matrice,
• sumu pozitivnih elemenata matrice,
• sumu elemenata matrice s parnim indeksima.
*/

const int red = 3, kol = 3;

void unos (int niz[][kol], int red, int kol) {

	if (red < 0)
		return;

	niz[red][kol] = rand () % 10 + 1;
	

	if (kol == 0) {

		kol = 2;
		unos (niz, red - 1, kol);
		
	}
	else
		unos (niz, red, kol-1);
}

void ispis (int niz[][kol], int red, int kol) {

	if (red < 0)
		return;

	cout <<setw(3)<< niz[red][kol];

	if (kol == 0) {

		cout << endl;
		kol = 2;
		ispis (niz, red - 1, kol);

	}
	else
		ispis (niz, red, kol - 1);

}

int suma (int niz[][kol], int red, int kol) {

	if (red < 0)
		return 0;

	if (kol > 0)
	return niz[red][kol] + suma (niz, red, kol-1);

	if (kol == 0) {

		kol = 2;
		return niz[red][kol] + suma (niz, red - 1, kol);

	}
	else
		return niz[red][kol] + suma (niz, red, kol - 1);


}

int sPoz (int niz[][kol], int red, int kol) {

	if (red < 0)
		return 0;

	if (niz[red][kol] > 0) {

		if (kol > 0)
			return niz[red][kol] + suma (niz, red, kol - 1);

		if (kol == 0) {

			kol = 2;
			return niz[red][kol] + suma (niz, red - 1, kol);

		}
		else

			return niz[red][kol] + suma (niz, red, kol - 1);

	}
}

int iPar (int niz[][kol], int red, int kol) {

	if (red < 0)
		return 0;

	if (red % 2 == 0 || kol % 2 == 0) {

		if (kol > 0)
			return niz[red][kol] + iPar (niz, red, kol - 1);

		if (kol == 0) {

			kol = 2;
			return niz[red][kol] + iPar (niz, red - 1, kol);

		}
		else

			return niz[red][kol] + iPar (niz, red, kol - 1);

	}
	else
		iPar (niz, red, kol - 1);
}

void main () {

	int niz[red][kol];

	cout << "Upisi clanove niza" << endl;
	unos (niz, red-1, kol-1);

	cout << endl << endl << "ISPIS" << endl<<endl;
	ispis (niz, red-1, kol-1);

	cout << "\nSuma svih elemenata niza je: " << suma (niz, red-1, kol-1);

	cout << "\nSuma elemenata sa parnim indeksom je: "<<iPar (niz, red - 1, kol - 1);

	system ("pause>0");
}
