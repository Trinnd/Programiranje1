/*
Napišite program u kojem ćete omogućiti unos prirodnog broja. Provjerite je li broj trivijalan (prost) uz pomoć funkcije:
bool trivijalan (int);. U slučaju da broj nije trivijalan (prost) odredite i ispište sve njegove djelitelje uz pomoć funkcije:
void djelitelji(int);
*/

#include<iostream>

using namespace std;

void unos (int&);
bool trivijalan (int);
void djelitelj (int);

int main () {

	int broj;

	unos (broj);

	if (trivijalan (broj))
		cout << "Broj je trivijalan" << endl;
	else
		djelitelj (broj);

	system ("pause>0");
	return 0;
}

void unos (int& broj) {

	do {
		cout << "Unesite prirodni broj" << endl;
		cin >> broj;

	} while (broj < 0);

}

bool trivijalan (int broj) {

	for (int i = 2; i <= broj/2; i++) {

		if (broj % i == 0)
			return false;
		else
	return true;
	}
}

void djelitelj (int broj) {

	for (int i = 1; i <= broj / 2; i++) {

		if (broj % i == 0)
			cout << i << endl;
		
	}

}
