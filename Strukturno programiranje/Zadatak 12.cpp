#include<iostream>

using namespace std;

int novi (int&);

int main () {

	int n;

	do {
		cout << "Unesite cijeli broj veci od 50 a manji od 5000000" << endl;
		cin >> n;
	} while (n < 50 && n>5000000);

	cout << n << endl;

	

	cout << novi(n) << endl;


	system ("pause>0");
	return 0;
}

int novi (int& broj) {

	int temp = 0, novi = 0;

	while (broj > 0) {

		temp = broj % 10;

		if (temp % 2 == 0)
		novi = 10 * novi + temp;

		broj /= 10;
	}

	return novi;

}
