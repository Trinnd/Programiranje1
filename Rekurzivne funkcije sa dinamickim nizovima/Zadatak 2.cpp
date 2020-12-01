#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti. 
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., 
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. 
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
*/

void rek (int* pok, int vel, int& brojac, int temp) {

	if (brojac == vel)
		return;

	temp *= 2 ;

	if (temp < 0)
		return;

	*(pok + brojac) = temp;
	brojac++;

	rek (pok, vel, brojac, temp);
}

int main () {

	int vel, brojac = 0, temp = 1;

	cout << "Unesi velicinu jednodimenzionalnog dinamickog niza" << endl;
	cin >> vel;

	int* niz = new int[vel] {};

	rek (niz, vel, brojac, temp);

	for (int i = 0; i < vel; i++)
		cout << *(niz+i) << endl;

	delete[]niz;
	niz = nullptr;

	return 0;
	system ("pause>0");
}
