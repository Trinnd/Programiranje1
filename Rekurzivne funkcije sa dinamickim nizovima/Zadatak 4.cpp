#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti faktorijelom rednog broja člana niza (1!, 2!, 3!, 4!...).
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
Obavezno sve riješiti jednom rekurzivnom funkcijom.
*/

void rek (int* niz, int vel, int i = 0) {

	if (i < 0 || i >= vel || vel < 0)
		return;

	if (i == 0)
		*(niz + i) = 1;
	else {

		int temp = *(niz + i - 1) * (i + 1);

		if (temp < 0)
			return;

		*(niz + i) = temp;

	}
		

	rek (niz, vel, i+1);
}

int main () {

	int vel;

	cout << "Unesi velicinu dinamickog jednodimenzionalnog niza" << endl;
	cin >> vel;

	int* niz = new int[vel];

	rek (niz, vel);

	for (int i = 0; i < vel; i++)
		cout << *(niz+i)<<endl;

	return 0;
	system ("pause>0");
}
