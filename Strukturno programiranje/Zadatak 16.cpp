#include <iostream>
using namespace std;

/*
Omogučiti unos dva broja X i Y iz intervala od 10 do 5000. Kreirati program koji će pronaći i ispisati sve brojeve od X do Y 
(uključujući granične vrijednosti) za koje važi da je obrnuti broj djeljiv sa njegovom sumom cifara.
Za olakšanje rješenja zadataka napraviri funkcije za obrtanje poretka cifara i za sumu cifara.

Npr. Za broj 144 vrijedi da mu je suma cifara 9 i da je broj koji se dobije nakon što se njegove cifre obrnu 441, djeljiv sa 9.

Definišite vrijednosti intervala [X, Y]: 11 150
Brojevi koji ispunjuju dati uslov: 18 20 21 24 27
*/

void unos (int&, int&);
int obrt (int);
int suma (int);

int main () {

	int x = 0, y = 0;

	unos (x, y);

	for (int i = x; i < y; i++)
		if (obrt (i) % suma (i) == 0)
			cout << i << " ";

	return 0;
	system ("pause>0");
}

void unos (int& x, int& y) {

	while(x>=y)
	do {

		cout << "Unesite pocetnu vrijednost intervala" << endl;
		cin >> x;

		cout << "Unesite krajnju vrijednost intervala" << endl;
		cin >> y;
		
	} while ((x < 10 || x>5000) || (y < 10 || y>5000));

}

int obrt (int broj) {

	int novi = 0, temp = 0;

	while (broj > 0) {

		temp = broj % 10;
	
		novi = 10 * novi +temp;

		broj /= 10;

	}
	return novi;
}

int suma (int broj) {

	int suma = 0, temp = 0;

	while (broj > 0) {

		temp = broj % 10;

		suma += temp;

		broj /= 10;

	}
	return suma;
}
