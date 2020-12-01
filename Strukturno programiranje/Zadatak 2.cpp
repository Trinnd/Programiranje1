#include <iostream>
using namespace std;

/*
Napisati program koji korisniku omogućava unos realnog broja x i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom jednog od sljedećih karaktera: 's' (sin), 'c' (cos).
U slučaju da korisnik unese karakter koji ne odgovara niti jednoj od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir. 
Za određenu funkciju sin() izraz je:

f(x) = 1 + [1/(sin(x) + x)] + [2/(sin(x/2) + x)] + ... + [x/(sin(x/x) + x)]
*/

void fun (char&);
void x (float&);
void s (float);
void c (float);

int main () {

	float n;
	char f;

	x (n);
	fun (f);

	switch (f) {

	case 's':
		cout << "Odabrali ste funkciju sinus i rezultat je:" << endl;
		s (n);
		break;
	case 'c':
		cout << "Odabrali ste funkciju kosinus i rezultat je:" << endl;
		c (n);
		break;

	}


	return 0;
	system ("pause>0");
}


void x (float& n) {

	cout << "Unesite realnu vrijednost x" << endl;
	cin >> n;

}

void fun (char& f) {

	cout << "Odaberite funkciju upisom slova [s] za sinus i [c] za kosinus" << endl;

	do {

		cin >> f;

		if (f != 's' && f != 'c')
			cout << "Pogresan unos. Unesite [s] - sinus ili [c] - kosinus" << endl;

	} while (f != 's' && f != 'c');

}

void s (float s) {

	float rez = 1;

	for (int i = 1; i <= s; i++) {

		rez += i / (sin (s / i) + s);

	}
	cout << rez << endl;
}

void c (float s) {

	float rez = 1;

	for (int i = 1; i <= s; i++) {

		rez += i / (cos (s / i) + s);

	}
	cout << rez << endl;
}
