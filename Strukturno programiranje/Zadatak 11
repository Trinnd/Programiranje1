/*
Napišite program, poštujući sve faze procesa programiranja, koji će ispisati sve troznamenkaste brojeve koji su jednaki 
sumi faktorijela svojih znamenki – ABC = A! + B! + C! Upotrijebite funkcije:

bool provjera(int);
int faktorijel(int);
*/
#include<iostream>

using namespace std;

bool provjera (int);
int faktorijel (int);

int main () {


	for (int i = 100; i < 1000; i++) {
		if (provjera(i))
			cout << i << endl;
	}

	system ("pause>0");
	return 0;
}

bool provjera (int broj) {

	int temp = 0, suma = 0, fakt = 1;

		for (int i = 100; i < 1000; i++) {

			if (faktorijel (i) == i) {
				return true;
			}
			
		}




}

int faktorijel (int broj) {

	int fakt = 1, suma = 0, temp = 0;

	while (broj > 0) {

		temp = broj % 10;

		for (int i = 1; i < temp; i++) {

			fakt *= i;

			suma += fakt;
		}

		broj /= 10;

	}
	return suma;
}
