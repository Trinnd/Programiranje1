/*
Napišite program u kojem ćete deklarirati matricu 5x4. Redak u matrici je učenik, a kolona predmet. Uz pomoć funkcije:
 
vod unos (int [] [4]); omogućite unos samo prolaznih ocjena (2-5) za sve učenike;
float prosjek(int []); izračunati prosječnu ocjenu učenika; za kojeg od učenika će se računati prosjek bira korisnik;
int prebroji (int [][4], int); prebrojati koliko učenika ima ocjenu 4 i više na predmetu po izboru korisnika.

*/
#include<iostream>
#include<iomanip>

using namespace std;
const int red = 5;
const int kol = 4;

void unos (int[][kol]);
float prosjek (int[]);

int main () {

	int niz[red][kol], end[6] = {0}, ucenik = 0;

	unos (niz);

	do {
		cout << "Odaberite kojem cete uceniku izracunati prosjecnu ocjenu" << endl;
		cin >> ucenik;
	} while (ucenik < 0 && ucenik > 5);


	for (int i = 0; i < red; i++) {
		cout << endl;
		for (int j = 0; j < kol; j++) {

			cout <<setw(5)<< niz[i][j];

		}
	}


		for (int j = 0; j <kol; j++) {

			end[j] = niz[ucenik][j];
			
			
		}
			cout<<endl << prosjek (end) << endl;
	

	system ("pause>0");
	return 0;
}

void unos (int niz[][kol]) {

	for (int i = 0; i < red; i++) {
		cout << "Ucenik " << i + 1 << endl;
		for (int j = 0; j < kol; j++) {

			do {

				cout << "Unesite ocjene za ucenika " << i + 1 << endl;
				cout << "Predmet " << j + 1 << endl;

				//cin >> niz[i][j];
				niz[i][j] = rand () % 10 + 1;

			} while (niz[i][j] < 2 || niz[i][j]>5);

		}
	}

}

float prosjek (int end[]) {

	int suma = 0, brojac = 0;
	float rez = 0;

	for (int i = 0; i < kol; i++) {

		suma += end[i];
		brojac++;
	}

	rez = suma / brojac;

	return rez;
}
