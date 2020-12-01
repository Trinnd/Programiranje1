#include <iostream>
using namespace std;

/*
Napisati program koji omogućava korisniku unos integer vrijednosti veće od 100. Napisati funckiju koja će provjeriti da li je uneseni broj 
u isto vrijeme i prost i "palindrom", odnosno da li je isti broj i kada se obrnnu sve cifre. Po potrebi koristiti dodatne funkcije.
Npr. brojevi 383, 727, 757, 787, 797, 919, 929 su u isto vrijeme i prosti brojevi i "palindromi".

10<a>100 i 1000<b>2000

*/

void provjera (int, int);
bool prost (int);
bool palindrom (int);

int main () {

	int a = 0, b = 0;

	do {

		cout << "Unesite pocetnu vrijednost" << endl;
		cin >> a;

		cout << "Unesite krajnju vrijednost" << endl;
		cin >> b;


	} while ((a < 10 || a>100) && (b < 1000 || b>2000));


	cout << "Brojevi koji su prosti i palindrom u zadanom rangu brojeva su: " << endl;
	provjera (a, b);

	return 0;
	system ("pause>0");
}

void provjera (int a, int b) {

	for (int i = a; i < b; i++)
		if (prost (i)==true && palindrom (i)==true)
			cout << i<<" ";

}

bool prost (int broj) {

	for (int i = 2; i < broj; i++)
		if (broj % i != 0)
			return true;
	return false;

}

bool palindrom (int broj) {

	int temp = 0, broj2 = broj, novi = 0;

	while (broj > 0) {

		temp = broj % 10;
		//456 temp = 6   novi *=10+temp;
		novi =10*novi+temp;

		broj /= 10;
	}

	if (broj2 == novi)
		return true;
	return false;

}
