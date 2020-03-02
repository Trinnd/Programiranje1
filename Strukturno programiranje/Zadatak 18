#include <iostream>
using namespace std;

/*
Napisati program koji omogućava unos pozitivnog broja n te pronalazi njegove parne cifri i formira novi broj u kojem su parne 
cifra zamijenjena cifrom '5'. Dodatno program treba ispisati razliku unesenog i broja koji se dobije nakon zamjene najmanje cifre.
*/

void unos (int&);
void novi (int&);

int main () {

	int broj;

	cout << "Unesi pozitivan broj" << endl;
	unos (broj);

	novi (broj);
	cout << "Novi broj je: " << broj;

	return 0;
	system ("pause>0");
}

void novi (int& broj) {

	int temp = 0, novi = 0, brojac = 0;

	while (broj > 0) {

		temp = broj % 10;

		if (temp % 2 == 0) {

			temp = 5;
			novi = temp * pow (10, brojac) + novi;

		}
		else
			novi = temp * pow (10, brojac) + novi;


		brojac++;
		broj /= 10;
	}
	broj = novi;
}

void unos (int& broj) {

	do {

		cin >> broj;

	} while (broj < 0);

}
