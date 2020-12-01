/*SORTIRANJE NIZA PO SREDNJOJ CIFRI TROCIFRENIH BROJEVA*/

#include<iostream>

using namespace std;

void unos (int, int[]);
void provjera (int[], int);

const int vel = 10;

int main () {

	int n = 0, niz[vel];

	do {

		cout << "Upisite prirodni broj manji ili jednako 10." << endl;
		cin >> n;

	} while (n < 1 || n>10);

	unos (n, niz);

	provjera (niz, n);

	cout << endl;

	for (int i = 0; i < n; i++) {

		cout << niz[i] << endl;

	}

	system ("pause>0");
	return 0;
}

void unos (int n, int niz[]) {

	int broj;

	for (int i = 0; i < n; i++) {

		cout << "Unesite " << i + 1 << ". clan niza:" << endl;
		cin >> broj;

		if (broj > 99 && broj < 1000) {
			niz[i] = broj;
		}
		else {
			i--;
			cout << "Pogresan unos" << endl;
		}

	
	}

}

void provjera (int niz[], int n) {

	bool promjena = true;
	int temp, srednja1, srednja2;
	
	while (promjena) {
		
		promjena = false;

		for (int i = 0; i < n-1; i++) {

			srednja1 = (niz[i] / 10) % 10;
			srednja2 = (niz[i + 1] / 10) % 10;

			if (srednja1 > srednja2) {

				temp = niz[i];
				niz[i] = niz[i + 1];
				niz[i + 1] = temp;
				promjena = true;
			}
			
		}
	}
}
