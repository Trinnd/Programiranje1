/*
Napišite program u kojem ćete omogućiti unos prirodnog broja. Provjerite je li broj trivijalan (prost)uz pomoć funkcije:

//bool trivijalan (int);
U slučaju da broj nije trivijalan (prost) prebrojite sve njegove djelitelje uz pomoć funkcije:

//int djelitelji(int);
*/

#include <iostream>

using namespace std;

void unos (int&);
bool trivijalan (int);
int djelitelji (int);

int main () {

	int broj = 0;

	unos (broj);

	if (trivijalan (broj))
		cout << "Broj je trivijalan" << endl;


	cout <<"Broj njegovih djelitelja je: "<< djelitelji (broj)<<endl;
	

	system ("pause>0");
	return 0;
}

void unos (int& broj) {

	do {

		cin >> broj;

	} while (broj < 0);

}

bool trivijalan (int broj) {

	for (int i = 2; i < broj / 2; i++) {

		if (broj % i == 0)
			return false;

		return true;
	}

}

int djelitelji (int broj) {

	int brojac = 0;
	
	for (int i= 2; i < broj / 2; i++) { 

		if (broj % i == 0) {

			brojac++;
		}

	}
	return brojac;
}
