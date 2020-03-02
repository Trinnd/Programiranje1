#include <iostream>
using namespace std;

/*
Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100.
Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom", odnosno da li je isti
broj i kada se obrnnu sve cifre. Po potrebi koristiti dodatne funkcije. Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto
vrijeme i prosti brojevi i "palindromi".
*/

void unos (int&);
bool pal (int);
bool prost (int);


int main () {

	int broj = 0;

	unos (broj);

	if (prost (broj) == true && pal (broj) == true)
		cout << "Broj koji ste unijeli je i prost i palindrom." << endl;
	else
		cout << "Broj koji ste unijeli nema trazene osobine iz zadatka." << endl;

	return 0;
	system ("pause>0");
}

bool prost (int broj) {

	for (int i = 2; i < broj - 1; i++) {

		if (broj % i == 0)
			return false;

	}
	return true;
}

bool pal (int broj) {

	int temp = 0, novi = 0, por = broj;

	while (broj > 0) {

		temp = broj % 10;

		novi = 10 * novi + temp;

		broj /= 10;

	}

	if (por == novi)
		return true;
	else
		return false;

}

void unos (int& broj) {

	do {

		cin >> broj;

	} while (broj < 100);

}
