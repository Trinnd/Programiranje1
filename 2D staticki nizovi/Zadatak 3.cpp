/*
Napišite program u kojem ćete deklarirati niz od 7 cijelih brojeva. Uz pomoć funkcije:

void unos (int [], int); omogućite unos elemenata u niz;
float prosjecna(int [], int); izračunati prosječnu vrijednost elemenata niza;
bool opadajuci (int [], int); provjeriti jesu li elementi niza poredani u opadajućem poretku (n1 > n2 > n3 > n4 > n5 > n6 > n7);
*/

#include <iostream>

using namespace std;

void unos (int[], int);
float prosjecna (int[], int);
bool opadajuci (int[], int);

int main () {

	const int vel = 7;
	int niz[vel];

	unos (niz, vel);

	for (int i = 0; i < vel; i++) {
		cout << niz[i] << endl;
	}

	cout << "Prosjecna vrijednost niza je: " << prosjecna (niz, vel) << endl;

	if (opadajuci (niz, vel))
		cout << "Niz je opadajuci" << endl;
	else
		cout << "Niz nije u opadajucem poretku" << endl;

	system ("pause>0");
	return 0;
}

void unos (int niz[], int vel) {

	for (int i = 0; i < vel; i++) {

		do {

			cin >> niz[i];
			//niz[i] = rand () % 100 + 10;

		} while (niz[i] < 0);

	}


}

float prosjecna (int niz[], int vel) {

	int suma = 0;

	for (int i = 0; i < vel; i++) {

		suma += niz[i];

	}

	return suma / vel;

}

bool opadajuci (int niz[], int vel) {

	for (int i = 0; i < vel-1; i++) {

		if (niz[i] < niz[i + 1])
			return false;

			return true;
	}

}
