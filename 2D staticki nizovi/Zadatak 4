#include<iostream>
#include<iomanip>
using namespace std;

/*
Napišite program koji će omogućiti kreiranje matrice prirodnih brojeva 5x5. Uz pomoć funkcije:

//void unos (int [][5]); omogućite unos elemenata matrice; vodite računa da svi elementi matrice moraju biti prirodni brojevi;
//bool pozicija(int[][5], int &); pronaći prvi redak koji sadrži vrijednost 5; u slučaju da u matrici nema vrijednosti 5 
funkcija treba vratiti vrijednost false, a program treba ispisati odgovarajuću poruku;
//float prosjecna(int [][5], int); izračunati prosječnu vrijednost u retku za koji ste prethodnom funkcijom utvrdili da
sadrži vrijednost 5; u slučaju da ste prethodnom funkcijom ustanovili da u matrici nema broja 5 funkciju ne treba pozivati.
Ispis prvog retka koji sadrži vrijednost 5, prosječne vrijednosti u tom retku kao i zahtijevanih poruka vršite u funkciji main.
*/ 

const int vel = 5;

void unos (int[][vel]);
bool pozicija (int[][vel], int&);
float prosjecna (int[][vel], int);

int main () {

	int niz[vel][vel], red = -1;

	unos (niz);

	for (int i = 0; i < vel; i++) {
		cout << endl;
		for (int j = 0; j < vel; j++) {

			cout <<setw(5)<< niz[i][j];

		}
	}

	pozicija (niz, red);

	if (red == -1)
		cout <<endl<< "Ne postoji red koji ima vrijednost 5" << endl;

	else {
		cout << endl<<endl << "Red koji ima vrijednost 5 u nizu je ["<<red+1<<"]"<<endl;
		for (int i = 0; i < vel; i++) {

			cout <<setw(5)<< niz[red][i];

		}

	}

	cout <<endl<<endl<<"Prosjek reda koji ima vrijednost 5 je: "<< prosjecna (niz, red);

	system ("pause>0");
	return 0;
}

void unos (int niz[][vel]) {

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			do {

				//cin >> niz[i][j];
				niz[i][j] = rand () % 100 + 1;

			} while (niz[i][j] < 0);

		}
	}

}

bool pozicija (int niz[][vel], int& red) {

	for (int i = 0; i < vel; i++) {
		for (int j = 0; j < vel; j++) {

			if (niz[i][j] == 5) {
				red = i;
				return true;
			}
		}
	}
	return false;
}

float prosjecna (int niz[][vel], int red) {

	int suma = 0;

	for (int i = 0; i < vel; i++) {

		suma += niz[red][i];

	}
	return suma / vel;
}
