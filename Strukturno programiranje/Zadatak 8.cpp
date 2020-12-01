#include<iostream>
using namespace std;

/*
Napišite program, poštujući sve faze procesa programiranja, u kojem ćete za uneseni prirodni broj n 
izračunati sumu: S = 1! + 2! + … +n! Upotrijebite funkciju:

//float suma (int);
//int faktorijel(int);
*/

void unos (int&);
float suma (int);
int faktorijel (int);

int main () {

	int n = 0;

	unos (n);

	cout << "Rezultat je: " << suma (n)<<endl;
	cout << "Faktorijel je: " << faktorijel (n);

	system ("pause>0");
	return 0;
}

void unos (int& broj) {

	do {

		cin >> broj;

	} while (broj < 0);

}

int faktorijel (int broj) {

	int fakt = 1, suma = 0;

	for (int i = 1; i < broj; i++) {

		fakt *= i;

	}
	return fakt;

}

float suma (int broj) {

	float zbir = 0, fakt = 1;

	for (int i = 1; i < broj; i++) {

		fakt *= i;

		zbir += fakt;

	}

	return zbir;
}
