#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku unos broja n (uz uslov 10 <= n <= 1000). 
Zatim simulirati unos n slučajnih vrijednosti. Simuliranje unosa ostvariti funkcijom rand() % 1000 + 1.
Izračunati statističke podatke u kojem procentu se od n generisanih slučajnih vrijednosti pojavljuje prost broj.

Npr. Ako je generisano 10 brojeva (n = 10): 5,7,4,13,17,20,25,23,30,45, u ovom uzorku od 10 brojeva postoji 5 prostih brojeva 
pa je procenat prostih brojeva u ovom slučaju 50%.
*/

void unos (int&);
void gen (int);
bool prost (int);

int main () {

	int n = 0;

	unos (n);
	gen (n);

	return 0;
	system ("pause>0");
}

void unos (int& n) {

	do {

		cout << "Unesite n slucajnih vrijednosti" << endl;
		cin >> n;

	} while (n < 10 || n > 1000);

}

void gen (int n) {

	int broj = 0, brojac = 0;

	for (int i = 0; i < n; i++) {

		broj = rand () % 1000 + 1;
		cout << broj << endl;

		if (prost (broj) == true)
			brojac++;
	}
	cout << "Procenat prostih brojeva u " << n << " generisanih brojeva je " << float (100 * brojac / n) << "%";
}

bool prost (int broj) {

	for (int i = 2; i < broj-1; i++) 
		if (broj % i == 0)
			return false;
	return true;
}
