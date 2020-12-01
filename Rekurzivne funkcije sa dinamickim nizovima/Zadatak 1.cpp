#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati funkciju koja će taj niz popuniti serijom Fibonacci brojeva počevši od broja 1. 
Za pronalazenje elemenata Fibonacci serije obavezno koristiti rekurzivnu funkciju.
Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
*/

void rek (int* pok, int vel, int brojac=0) {

	if (brojac >= vel)
		return;

	if (brojac == 0) {

		*(pok + 0) = 1;
		*(pok + 1) = 1;
		brojac++;
	}
	else {

		int temp = *(pok + brojac - 1) + *(pok + brojac - 2);

		*(pok + brojac) = temp;

		if (temp < 0)
			return;

	}
	rek (pok, vel, brojac + 1);
	}

int main () {

	int vel;
	cout << "Unesite velicinu jednodimenzionalnog dinamickog niza" << endl;
	cin >> vel;

	int* pok = new int[vel];

	rek (pok, vel);

	for (int i = 0; i < vel; i++)
		cout << *(pok + i) << endl;

	delete[]pok;
	pok = nullptr;

	return 0;
	system ("pause>0");
}
