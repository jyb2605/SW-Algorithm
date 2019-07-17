/*
 * D2
 * 1288. 새로운 불면증 치료법
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, number, checkCount = 0;
		vector<bool> check(10, false);
		cin >> N;
		number = N;

		cout << '#' << _case << ' ';

		while (checkCount < 10) {
			int tmp = number;

			while (tmp != 0) {
				int remain = tmp % 10;
				if (!check[remain]) {
					check[remain] = true;
					checkCount++;
				}
				tmp /= 10;
			}

			number += N;
		}

		number -= N;

		cout << number << '\n';
	}

	return 0;
}