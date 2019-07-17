/*
 * D2
 * 1945. 간단한 소인수분해
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int number;
		cin >> number;

		cout << '#' << _case << ' ';
		
		int count = 0;

		while ((number % 2) == 0) {
			number /= 2;
			count++;
		}
		cout << count << ' ';
		
		count = 0;

		while ((number % 3) == 0) {
			number /= 3;
			count++;
		}
		cout << count << ' ';
		
		count = 0;

		while ((number % 5) == 0) {
			number /= 5;
			count++;
		}
		cout << count << ' ';

		count = 0;

		while ((number % 7) == 0) {
			number /= 7;
			count++;
		}
		cout << count << ' ';

		count = 0;

		while ((number % 11) == 0) {
			number /= 11;
			count++;
		}
		cout << count<<'\n';
	}

	return 0;
}