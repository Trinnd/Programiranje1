#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler (fudbaler je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza.

struct fudbaler
{
	int *godRodjenja;
	int *brojIgraca;
	int *golovi;
};

Redovi dvodimenzionalnog niza predstavljaju razlicite timove a kolone prestavljaju igrače u tim timovima.
Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći tim sa najvećim prosjekom.
Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova. 
Radi lakšeg testiranja programa obavezno u funciji unosa podataka omogućiti da se podaci generišu tako što će se:

godRodjenja generisati: 1980 + rand() % ((2000 + 1) - 1980) (uzmite ovaj dio code-a da dobijete slučajne brojeve u rangu 1980-2000)
brojIgraca generisati: rand() % 30 + 1
golovi generisati: rand() % 5
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivaca.
*/

struct fudbaler
{
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

	void dealociraj ();
};

void fudbaler::dealociraj () {

	delete godRodjenja;
	delete brojIgraca;
	delete golovi;

}

void unos (fudbaler&);
int prosjekKlub (fudbaler**, int);
int prosjekIgrac (fudbaler**, int);

//void ispis (fudbaler **, int);

int main () {

	int n;

	cout << "Unesite velicinu 2d dinamickog niza" << endl;
	cin >> n;

	fudbaler** niz = new fudbaler * [n];

	for (int i = 0; i < n; i++)
		*(niz+i) = new fudbaler[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			unos (*(*(niz + i) + j));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			(*(niz + i) + j)->dealociraj ();
		delete[] * (niz + i);
	}

	delete[]niz;

	/*for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			ispis (niz, n);*/

	return 0;
	system ("pause>0");
}

void unos (fudbaler& p) {

	p.godRodjenja = new int;
	*p.godRodjenja = 1980 + rand () % ((2000 + 1) - 1980);

	p.brojIgraca = new int;
	*p.brojIgraca = rand () % 30 + 1;

	p.golovi = new int;
	*p.golovi = rand () % 5;

}

int prosjekKlub (fudbaler** niz, int vel) {

	int suma = 0, prosjek = 0, indeks = 0, min = INT_MIN;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			suma += *niz[j][i].golovi;

		}
		prosjek = suma / vel;

		if (prosjek > min)
			indeks = i;
	}
	return indeks;
}

int prosjekIgrac (fudbaler** niz, int vel) {

	int suma = 0, prosjek = 0, indeks = 0, indeksp = 0, min = INT_MAX, max = INT_MIN;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			suma += *niz[j][i].golovi;

		}
		prosjek = suma / vel;

		if (prosjek < min) {

			min = prosjek;
			indeks = i;
		}
	}
	
	for (int i = 0; i < vel; i++) {

		if (*niz[vel][indeks].golovi > max) {

			max = *niz[vel][indeks].golovi;
			indeksp = i;
		}
	}
	return indeksp;
}

//void ispis (fudbaler** niz, int vel) {
//
//	for (int i = 0; i < vel; i++) {
//		for (int j = 0; j < vel; j++) {
//
//			cout << "||------------------------------||" << endl;
//			cout << "Broj igraca: " << endl;
//			cout << *(*(niz + i) + j)->brojIgraca << endl;
//			cout << "Godina rodjenja: " << endl;
//			cout << *(*(niz + i) + j)->godRodjenja << endl;
//			cout << "Golovi: " << endl;
//			cout << *(*(niz + i) + j)->golovi << endl;
//			cout << "||------------------------------||" << endl;
//
//		}
//	}
//}
