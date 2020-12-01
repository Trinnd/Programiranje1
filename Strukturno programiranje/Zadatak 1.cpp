#include <iostream>
using namespace std;

/*
Napisati program u kojem je potrebno unijeti odabrani broj cifara počevši od cifre najveće težinske vrijednosti,
pa od njih sastaviti i ispisati prirodni broj. Unos cifara se prekida kada se unese broj manji od 0 ili veći od 9. Ispis neka bude oblika:

Upisi cifru: 2
Upisi cifru: 8
Upisi cifru: -1
Broj sastavljen od zadanih cifara je 28.
*/


int main () {

	int cifra = 0, novi = 0;

	while (cifra >= 0 && cifra < 9) {

		cout << "Upisi cifru: ";
		cin >> cifra;

		if (cifra >= 0 && cifra < 9)
		novi = 10 * novi + cifra;

	}

	cout << "Broj sastavljen od zadanih cifri je: " << novi << endl;

	return 0;
	system ("pause>0");
}
