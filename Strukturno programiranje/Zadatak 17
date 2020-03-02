/*
Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegovu najmanju cifru i formira novi
broj u kojem je najmanja cifra zamijenjena cifrom '3'. Ukoliko uneseni broj n sadrži više istih cifara koje su
najmanje, tada je potrebno zamijeniti svaku od njih. Dodatno program treba ispisati razliku unesenog i broja
koji se dobije nakon zamjene najmanje cifre.
Primjer izlaza:
Unesite pozitivan broj: 5865
Broj nakon promjene najmanje cifre: 3863
Razlika brojeva iznosi: 2002
*/
#include<iostream>

using namespace std;

int cifra (int);
int novi (int);

int main () {

	int n = 0;

	do {

		cin >> n;

	} while (n < 0);

	cout<<novi (n);

	system ("pause>0");

	return 0;
}

int cifra (int broj) {

	int temp = 0, min = 9;

	while (broj > 0) {

		temp = broj % 10;

		if (temp < min) {
			min = temp;
		}

		broj /= 10;

	}
	return min;
}

int novi (int broj) {

	int mala = cifra (broj);
	int temp = 0, brojac = 0, novi = 0;
	
	while (broj > 0) {
		//235
		temp = broj % 10;

		if (temp == mala) {
			temp = 3;

		}

		novi += temp * pow (10, brojac);

		brojac++;
		broj /= 10;

	}
	return novi;
}
