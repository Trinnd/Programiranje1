#include <iostream>
using namespace std;

/*
Napisati program koji će omogućiti korisniku unos broja n ( 10 <= n <= 1000). 
Zatim simulirati n bacanja kockice (kockica ima 6 strana i na tim stranicama su brojevi 1-6).
Simuliranje bacanja svake kockice ostvariti funkcijom rand() % 6 + 1.
Izračunati statičke podatke u kojem procentu ukupnog bacanja se dobiva svaki od mogućih brojeva 1-6. 
Obavezno koristiti switch statement za zbrajanje rezultata bacanja kockice.

Napomena: Po želji kreirati dodatne funkcije da se olakša rješavanje zadataka.
*/

void unos (int&);
void bacanje (int);

void main () {

	int n = 0;
	unos (n);

	bacanje (n);


	system ("pause>0");
}

void unos (int& broj) {

	do {

		cout << "Unesite broj veci od 10 a manji od 1000" << endl;
		cin >> broj;

	} while (broj < 10 || broj > 1000);

}

void bacanje (int vel) {

	int kocka = 0, i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0, i6 = 0;

	for (int i = 0; i < vel; i++) {

		kocka = rand () % 6 + 1;

		switch (kocka) {

		case 1:
			i1++;
			break;
		case 2:
			i2++;
			break;
		case 3:
			i3++;
			break;
		case 4:
			i4++;
			break;
		case 5:
			i5++;
			break;
		case 6:
			i6++;
			break;

		}

	}

	cout << "Procenat broja jedan u " << vel << " bacanja kocke je: " << float(100*i1/vel) <<"%"<< endl;
	cout << "Procenat broja dva u " << vel << " bacanja kocke je: " << float(100 * i2 / vel) << "%"<< endl;
	cout << "Procenat broja tri u " << vel << " bacanja kocke je: " << float(100 * i3 / vel) << "%"<< endl;
	cout << "Procenat broja cetiri u " << vel << " bacanja kocke je: " << float(100 * i4 / vel) << "%"<< endl;
	cout << "Procenat broja pet u " << vel << " bacanja kocke je: " << float(100 * i5 / vel) << "%"<< endl;
	cout << "Procenat broja sest u " << vel << " bacanja kocke je: " << float(100 * i6 / vel) << "%"<< endl;
}
