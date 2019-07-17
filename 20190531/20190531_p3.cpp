/*
 * D2
 * 1970. 쉬운 거스름돈
 */
#include <iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		cout << '#' << _case << '\n';

		int num;
		cin >> num;

		int quotient;

		quotient = num / 50000;
		cout << quotient<<' ';
		num %= 50000;

		quotient = num / 10000;
		cout << quotient << ' ';
		num %= 10000;


		quotient = num / 5000;
		cout << quotient << ' ';
		num %= 5000;


		quotient = num / 1000;
		cout << quotient << ' ';
		num %= 1000;


		quotient = num / 500;
		cout << quotient << ' ';
		num %= 500;

		quotient = num / 100;
		cout << quotient << ' ';
		num %= 100;


		quotient = num / 50;
		cout << quotient << ' ';
		num %= 50;

		quotient = num / 10;
		cout << quotient << ' ';
		num %= 10;

		cout << endl;
	}

	return 0;
}