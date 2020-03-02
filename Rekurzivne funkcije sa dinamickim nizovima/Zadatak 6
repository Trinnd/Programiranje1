#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese velicinu jednodimenzionalnog dinamickog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz puniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512 itd., 
tako da je svaki slijedeci broj jednak prethodnom pomnozenom sa 2, pocevsi od broja 2.
Rekurzija se prekida kad se popuni cijeli niz ili kad se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivaca. 
Za olaksanje rjesenja, mozete izabrati prototip funkcija po zelji.
*/

void rek (int* niz, int vel, int& i, int temp = 2) {

	if (vel <= 0)
		return;


	if (i == 0) {
		*(niz + i) = temp;
		i++;
	}

	temp *= 2;
	if (temp < 0)
		return;

	*(niz + i) = temp;
	i++;

	rek (niz, vel - 1, i, temp);
}

int main () {

	int vel, j = 0;

	cout << "Unesi velicinu jednodimenzionalnog dinamickog niza" << endl;
	cin >> vel;

	int* niz = new int[vel];

	rek (niz, vel, j);

	for (int i = 0; i < j; i++)
		cout << *(niz + i)<<endl;

	return 0;
	system ("pause>0");
}
