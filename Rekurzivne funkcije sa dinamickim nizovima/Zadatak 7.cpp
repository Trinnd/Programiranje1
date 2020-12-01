#include <iostream>
using namespace std;

/*
Napišite program u kojem ćete upotrijebiti rekurzivnu funkciju čiji je zadatak računanje n-tog člana Fibonacci-jevog niza.
*/

int fib (int n) {

	//int fib1, fib2;

	if (n <= 1)
		return n;

	int fib1 = fib (n - 1);
	int fib2 = fib (n - 2);

	return fib1 + fib2;

}

void main () {

	int n;

	cout << "Unesite n-ti clan niza" << endl;
	cin >> n;

	cout << fib (n) << endl;

	system ("pause>0");
}
