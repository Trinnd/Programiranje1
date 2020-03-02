#include <iostream>
using namespace std;

/*
fibonacijev niz sa rekurzivnom funkcijom
*/

int fib (int n) {

	int f1, f2;

	if (n <= 1)
		return n;

	f1 = fib (n - 1);
	f2 = fib (n - 2);

	return f1 + f2;

}

int main () {

	int n;

	while (1) {

		cout << "Odredite granicu niza" << endl;

		cin >> n;

		cout << fib (n)<<endl;
	}

	system ("pause>0");
	return 0;
}
