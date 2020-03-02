#include <iostream>
using namespace std;

/*
Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100.
Napisati funckiju koja će provjeriti da li je uneseni broj u isto vrijeme i prost i "palindrom",
odnosno da li je isti broj i kada se obrnnu sve cifre. Po potrebi koristiti dodatne funkcije. 
Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".
*/

void unos (int&);
bool palindrom (int);
bool prost (int);

void main () {

	int broj = 0;

	unos (broj);

	cout << "Unijeli ste broj: " << broj << endl;
	if (palindrom (broj)==true)
		cout << "Broj je i prost i palindrom" << endl;
	else
		cout << "Uneseni broj ne odgovara uslovu zadatka" << endl;

	system ("pause>0");
}

bool palindrom (int broj) {

	int temp = 0, novi = 0, check = broj;

	if (prost (broj)) {

		while (broj > 0) {

			temp = broj % 10;
			novi = 10 * novi + temp;
			broj /= 10;

		}

		if (novi == check)
			return true;
	}

}

bool prost (int broj) {

	for (int i = 2; i < broj - 1; i++) 
		if (broj % 2 == 0)
			return false;
	return true;

}

void unos (int& broj) {

	do {

		cin >> broj;

	} while (broj < 100);

}
