/*
 * D2
 * 1926. 간단한 369게임
 */
#include <iostream>
using namespace std;

int main() {
	int N;
	bool isClab;
	cin >> N;

	for (int num = 1; num <= N; num++) {
		int tmp = num;
		isClab = false;

		while (tmp != 0) {
			if (tmp % 10 != 0 && (tmp % 10) % 3 == 0) {
				cout << '-';
				isClab = true;
			}
			tmp /= 10;
		}

		if (!isClab) {
			cout << num;
		}

		cout << ' ';
	}

	return 0;
}