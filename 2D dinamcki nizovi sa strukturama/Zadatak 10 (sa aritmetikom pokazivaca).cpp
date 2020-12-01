#include<iostream>
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
Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji) funkciju koja će pronaći
tim sa najvećim prosjekom. Zatim napraviti (i testirati u main funkciji) funkciju koja će pronaći igrača sa najviše golova u
timu sa najlošijim prosjekom golova. Radi lakšeg testiranja programa obavezno u funciji unosa podataka omogućiti da se podaci
generišu tako što će se:

godRodjenja generisati: 1980 + rand() % ((2000 + 1) - 1980) (uzmite ovaj dio code-a da dobijete slučajne brojeve u rangu 1980-2000)
brojIgraca generisati: rand() % 30 + 1
golovi generisati: rand() % 5
U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivaca.
*/

struct fudbaler { 

	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

};

void unos (fudbaler&);
int tim (fudbaler**, int);
int mit (fudbaler**, int);
int player (fudbaler**, int, int);

int main () {

	int vel;

	cout << "Unesite velicinu dvodimenzionalnog dinamickog niza" << endl;
	cin >> vel;

	fudbaler** niz = new fudbaler * [vel];
	for (int i = 0; i < vel; i++)
		*(niz + i) = new fudbaler[vel];

	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			unos (*(*(niz + i) + j));

	int Bclub = tim (niz, vel), Wclub = mit (niz, vel);
	cout << "Klub sa najboljim prosjekom je: " << Bclub + 1 << "\n";
	cout << "Igrac na najvise postignutih pogodaka u timu sa najlosijim prosjekom je: " << player (niz, vel, Wclub)<<endl;

	return 0;
	system ("pause>0");
}

void unos (fudbaler& o) {

	o.brojIgraca = new int;
	*o.brojIgraca = rand () % 30 + 1;

	o.godRodjenja = new int;
	*o.godRodjenja = 1980 + rand () % ((2000 + 1) - 1980);

	o.golovi = new int;
	*o.golovi = rand () % 5;

}

int tim (fudbaler** niz, int vel) {

	int indeks = 0,suma = 0, min = INT_MIN;
	double prosjek = 0;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++)
			suma += *(*(niz + i) + j)->golovi;

		prosjek = suma / vel;
		suma = 0;

		if (prosjek > min) {
			min = prosjek;
			indeks = i;
		}
	}
	return indeks;
}

int mit (fudbaler** niz, int vel) {

	int indeks = 0, suma = 0, prosjek = 0, max = INT_MAX;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++)
			suma += *(*(niz + i) + j)->golovi;

		prosjek = suma / vel;
		suma = 0;
		if (prosjek < max) {
			max = prosjek;
			indeks = i;
		}
		
	}
	return indeks;
}

int player (fudbaler** niz, int vel, int club) {

	int indeks = 0, min = INT_MIN;

	for (int i = 0; i < vel; i++) {

		if (*(*(niz + club) + i)->golovi > min) {
			indeks = i;
			min = *(*(niz + club) + i)->golovi;
		}
	}
	return indeks;
}
