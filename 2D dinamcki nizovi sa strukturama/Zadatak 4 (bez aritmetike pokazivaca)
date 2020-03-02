#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa uposlenik (uposlenik je struktura čija su obilježja data). 
Omogućiti korisniku da unese dimenzije niza.

struct uposlenik
{
	char *ID;
	char *imePrezime;
	float *plata;
}

Redovi dvodimenzionalnog niza predstavljaju različite odjele firme u kojima rade različiti radnici
(radi jednostavnosti rješenja podrazumijevati da svaki odjel ima isti broj radnika).
Omogućiti korisniku unos svih podataka za sve radnike, te napraviti funkciju koja će naći najveći prosjek plate po odjelima firme 
te ispisati koji je to redni broj odjela (indeks reda sa najvećim prosjekom) i koji je najveći prosjek plate.
*/

struct uposlenik
{
	char* ID;
	char* imePrezime;
	float* plata;
};

void unos (uposlenik&);
void prosjek (uposlenik**, int vel);

int main () {

	int vel;

	cout << "Upisi velicinu reda i velicinu kolone 2d dinamickog niza" << endl;
	cin >> vel;

	uposlenik** niz = new uposlenik * [vel];

	for (int i = 0; i < vel; i++)
		*(niz + i) = new uposlenik[vel];

	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			unos (niz[i][j]);

	prosjek (niz, vel);

	for (int i = 0; i < vel; i++)
		for (int j = 0; j < vel; j++)
			delete[]niz[vel];

	delete[]niz;
	niz = nullptr;

	return 0;
	system ("pause>0");
}

void unos (uposlenik& worker) {

	char lokalni[15];
	int vel;
	
	cout << "Upisi ID radnika" << endl;
	cin.ignore ();
	cin.getline (lokalni, 15);
	vel = strlen (lokalni);
	strcpy_s (worker.ID, vel+1, lokalni);
	lokalni[15] = { 0 };
	vel = 0;

	cout << "Upisi ime i prezime radnika" << endl;
	cin.getline (lokalni, 15);
	vel = strlen (lokalni);
	strcpy_s (worker.imePrezime, vel + 1, lokalni);

	cout << "Upisite iznos plate radnika" << endl;
	cin >> *worker.plata;
}

void prosjek (uposlenik** worker, int vel) {

	float suma = 0, prosjek = 0, min = INT_MIN, indeks = 0;

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			suma += *worker[i][j].plata;

		}
		prosjek /= suma;
		if (prosjek > min) {

			min = prosjek;
			indeks = i;
		}
	}
	cout << "Indeks sa najvecim prosjekom plate je: [" << indeks << "]";
}
