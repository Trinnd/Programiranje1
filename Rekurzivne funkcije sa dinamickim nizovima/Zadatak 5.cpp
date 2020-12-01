#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti random brojevima u opsegu od 1 do 100.
Za generisanje random brojeva koristiti rand() % 100 + 1. Punjenje niza se prekida kada se popuni cijeli niz ili kada se tri puta 
uzastopno dobije isti random broj. U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama. 
Obavezno koristiti aritmetiku pokazivača. Obavezno sve riješiti jednom rekurzivnom funkcijom.
*/

void rek (int* niz, int vel, int i = 0, int j = 0) {

	if (vel <= 0)
		return;

	int gen = rand () % 100 + 1;

	*(niz + i) = gen;

	if (*(niz + i - 1) == *(niz+i)&&*(niz+i)==*(niz+i-2))
		j++;

	if (j == 3)
		return;

	rek (niz, vel-1, i + 1, j);

}

int main () {

	int vel;

	cout << "Unesi velicinu jednodimenzionalnog dinamickog niza" << endl;
	cin >> vel;

	int* niz = new int[vel];

	rek (niz, vel);

	for (int i = 0; i < vel; i++)
		cout << niz[i]<< endl;

	return 0;
	system ("pause>0");
}
