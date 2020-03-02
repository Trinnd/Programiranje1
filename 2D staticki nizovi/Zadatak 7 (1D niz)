#include <iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void unos (int[], int);
float ini (int[], int[], int[], int);
bool opadajuci (int[], int);

int main () {

	const int velicina = 5;
	int niz1[velicina], niz2[velicina],niz3[velicina],odabir=0;

	cout << "Unesite clanove prvog niza" << endl;
	unos (niz1, velicina);

	cout << "Unesite clanove drugog niza" << endl;
	unos (niz2, velicina);

	ini (niz1, niz2, niz3, velicina);

	cout << "Odaberite koji niz zelite provjeriti: " << endl;

	do {
		cin >> odabir;
	} while (odabir < 1 || odabir>3);

	if (odabir == 1) {

		if (opadajuci (niz1, velicina)) {
			cout << "Niz je u opadajucem poretku" << endl;
		}
		else {
			cout << "Niz je u rastucem poretku" << endl;
		}


	}
	if (odabir == 2) {

		if (opadajuci (niz2, velicina)) {
			cout << "Niz je u opadajucem poretku" << endl;
		}
		else {
			cout << "Niz je u rastucem poretku" << endl;
		}
	}
	if (odabir == 3) {

		if (opadajuci (niz3, velicina)) {
			cout << "Niz je u opadajucem poretku" << endl;
		}
		else {
			cout << "Niz je u rastucem poretku" << endl;
		}
	}

	system ("pause>0");
	return 0;
}

void unos (int niz[], int v) {

	for (int i = 0; i < 5; i++) {
		
		cin >> niz[i];

	}

}

float ini (int niz1[], int niz2[], int niz3[], int size) {

	for (int i = 0; i < size; i++) {

		if (niz1[i] < niz2[i]) {

			niz3[i] = niz1[i];

		}
		else {
			niz3[i] = niz2[i];
		}
return niz3[i];
	}

	

}
bool opadajuci (int niz[], int size) {

	bool flag = true;

	for (int i = 0; i < 4; i++) {

		if (niz[i] < niz[i + 1]) {
			return false;
		}

	}
	return flag;

}
