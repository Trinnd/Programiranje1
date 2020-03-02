#include <iostream>
using namespace std;

/*
Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa „vrijeme“ (vrijeme je struktura čija su obilježja data u nastavku).
Omogućiti korisniku da unese dimenzije niza. 

	struct vrijeme { 
		float *temperatura; 
		float *vlaznostZraka;
		bool *padavine; 
		char *vrstaPadavine;
		float *kolicinaPadavine; 
		};

Redovi dvodimenzionalnog niza predstavljaju dane a kolone sate u danu. 
Omogućiti korisniku unos svih podataka za sve sate i dane, te napraviti funkciju koja će pronaći ispisati dan sa najvisom
i dan sa najnizom prosjecnom temperaturom. Potrebno je napraviti i funkciju koja ce racunati procenat sati sa temperaturom 
visom od 25.5 °C a u kojima je bilo padavina u odnosu na ukupan broj sati sa temperaturom visom od 25.5 °C. 
Takodjer je potrebno napraviti funkciju koja ce pronaci sat sa najvisom prosjecnom temperaturom u toku svih unesenih dana.
U ovom zadatku je zabranjeno indeksirati elemente niza uglatim zagradama. Obavezno koristiti aritmetiku pokazivača.
*/

struct vrijeme {

	float* temp;
	float* humidity;
	bool* padavine;
	char* vrstaP;
	float* kolicinaP;

};

void unos (vrijeme&);
void prosjek (vrijeme**, int red, int kol);
void procenat (vrijeme**, int red, int kol);
void dealokacija (vrijeme**, int);

int main () {

	int red, kol;

	cout << "Unesi broj redova 2d niza" << endl;
	cin >> red;
	cout << "Unesi broj kolona 2d niza" << endl;
	cin >> kol;

	vrijeme** weather = new vrijeme * [red];

	for (int i = 0; i < red; i++)
		weather[i] = new vrijeme[kol];


	return 0;
	system ("pause>0");
}

void dealokacija (vrijeme** weather, int kol) {

	for (int i = 0; i < kol; i++)
		delete[]weather[kol];

	delete[] weather;
	weather = nullptr;

}

void unos (vrijeme& weather) {

	char* lokalni = new char[20];
	int vel = 0;

	cout << "Unesi iznos temperature" << endl;
	cin >> *weather.temp;
	cout << "Unesi vlaznost u zraku" << endl;
	cin >> *weather.humidity;
	cout << "Da li je bilo padavina(unesite '1' za da, a '0' za ne)" << endl;
	cin >> *weather.padavine;
	cin.ignore ();

	if (*weather.padavine == true) {

		cin.getline (lokalni, 20);
		vel = strlen (lokalni)+1;
		strcpy_s ((weather.vrstaP), vel, lokalni);
		cin >> *weather.kolicinaP;
	}

}

void prosjek (vrijeme**weather, int red, int kol) {

	float* prosjek = new float [kol];
	float* suma = new float (0);
	float* max = new float (0);
	float* min = new float (100);
	int danMin = 0, danMax = 0, brojac = 0;

	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kol; j++) {
			*suma += *weather[i][j].temp;
			brojac++;
		}
		*(prosjek+i) = *suma / brojac;
	}

	for (int i = 0; i < red; i++) {

			if (*(prosjek + i) > * (max + i)) {

				*(max + i) = *(prosjek + i);
				danMax = i;
			}
			if (*(prosjek + i) < *(min + i)) {

				*(min + i) = *(prosjek + i);
				danMin = i;
			}

	}

	cout << "Najmanja prosjecna temperatura je: " << danMin + 1 <<". dana"<< endl;
	cout << "Najveca prosjecna temperatura je: " << danMax + 1 << ". dana" << endl;
}

void procenat (vrijeme** weather, int red, int kol) {

	float* percent = new float (0);
	float* suma = new float (0);
	int brojac = 0;

	for (int i = 0; i < red; i++) {
		for (int j = 0; j < kol; j++) {

			if (*weather[i][j].padavine == true && *weather[i][j].temp > 25.5)
				brojac++;

		}
	}

	*percent = 100 * brojac / kol;

	cout << "Procenat sati padavinama i temperaturom vecom od 25.5 je: " << *percent << "%" << endl;

}
