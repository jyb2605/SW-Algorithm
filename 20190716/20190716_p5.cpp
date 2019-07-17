/*
 * D2
 * 1986. 지그재그 숫자
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, result;
		cin >> N ;


		cout << '#' << _case << ' ';
		
		if (N % 2 == 0) {
			result = N / 2;
			result *= -1;
		}
		else {
			result = N / 2 + 1;
		}

		cout << result << '\n';
	}

	return 0;
}