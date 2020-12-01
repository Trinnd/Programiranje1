#include <iostream>
using namespace std;

/*
Napišite program, poštujući sve faze procesa programiranja, koji će ispisati sve troznamenkaste brojeve koji su jednaki 
sumi faktorijela svojih znamenki – ABC = (A + B)! + C! Upotrijebite funkcije:

//bool provjera (int);
//int faktorijel(int);
*/

bool provjera (int);
int faktorijel (int);

int main () {


	for (int i = 100; i < 1000; i++) {

		if (provjera (i)==true) {

			cout << i << endl;

		}

	}

	system ("pause>0");
	return 0;
}

bool provjera (int broj) {

	int temp = 0, suma = 0, fakt1 = 1, fakt2 = 1;
	
	while (broj > 0) {

		temp = broj % 10;

		if (broj > 99)
			fakt1 = faktorijel (temp);

		else {

			suma += temp;
			fakt2 = faktorijel (suma);

		}
			broj /= 10;
	}

	if (fakt1 + fakt2 != broj)
		return true;
	

}

int faktorijel (int broj) {

	int fakt = 1;

	for (int i = 1; i < broj; i++) {

		fakt *= i;

	}

	return fakt;

}
