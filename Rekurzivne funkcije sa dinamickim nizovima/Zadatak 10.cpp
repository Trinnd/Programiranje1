#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd., tako da je svaki
sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2. Zatim,korisnik unosi željeni broj te rekurzivnom funkcijom 
provjerava da li je taj broj član kreiranog niza. Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli. 
U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.
*/

void ispuna (int* niz, int vel, int brojac = 0, int pot = 1) {

	if (brojac>=vel)
		return;

	int temp = pow (2, pot);

	if (temp < 0)
		return;

	*(niz + brojac) = temp;

	ispuna (niz, vel, brojac + 1, pot + 1);

}

void provjera (int* niz, int vel, int broj, int& place, int brojac = 0) {

	if (brojac>=vel)
		return;

	if (broj == *(niz + brojac)) {

		place = brojac;
		return;

	}

	provjera (niz, vel, broj, place, brojac+1);
}

int main () {

	int vel, broj, mjesto = -1;

	cout << "Unesite velicinu jednodimenzionalnog niza" << endl;
	cin >> vel;

	int* niz = new int[vel];

	ispuna (niz, vel);

	for (int i = 0; i < vel; i++)
		cout << *(niz + i)<<endl;

	cout << "Unesite broj za provjeru clana" << endl;
	cin >> broj;

	provjera (niz, vel, broj, mjesto);

	if (mjesto >= 0)
		cout << "Trazeni broj je clan niza i nalazi se na " << mjesto + 1 << ". mjestu niza."<<endl;
	else
		cout << "Trazeni broj ne postoji u nizu" << endl;

	return 0;
	system ("pause>0");
}
