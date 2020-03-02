#include<iostream>
using namespace std;

/*
Napišite program u kojem ćete omogućiti unos dva prirodna broja. Provjerite čine li uneseni brojevi prijateljski par.
Prirodni brojevi a i b čine prijateljski par brojeva ako je zbir pravih djelitelja broja a (onih koji su manji od a)
jednak broju b i istovremeno zbir pravih djelitelja broja b jednak je broju a. Npr. Brojevi 220 i 284 su prijateljski brojevi.
Pravi djelitelji broja 220 su: 1, 2, 4, 5, 10, 11, 20, 22, 55, 110, a njihova suma iznosi 284; Pravi djelitelji
broja 284 su: 1, 2, 4, 71, 142 
a njihova suma iznosi 220. Upotrijebite funkcije:

//int suma_pravih_djelitelja (int);
//bool provjera (int, int);
*/

bool provjera (int, int);
int suma_pravih_djelitelja (int);

int main () {

	int a = 0, b = 0, suma1 = 0, suma2 = 0;

	do {

		cout << "Unesite prvi broj" << endl;
		cin >> a;

		cout << "Unesite drugi broj" << endl;
		cin >> b;

	} while (a < 0 || b < 0);

	suma1 = suma_pravih_djelitelja (a);
	suma2 = suma_pravih_djelitelja (b);

	if (provjera (a, suma2) && provjera (b, suma1))
		cout << "Brojevi su prijateljski" << endl;
	else
		cout << "Brojevi nisu prijateljski" << endl;
	

	system ("pause>0");
	return 0;
}

int suma_pravih_djelitelja (int broj) {

	int suma = 0;

	for (int i = 1; i < broj; i++) {

		if (broj % i == 0) {
			suma += i;
		}

	}
	return suma;
}

bool provjera (int broj, int suma) {

	if (broj == suma)
		return true;
	else
		return false;

}
