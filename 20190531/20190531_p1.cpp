/*
 * D2
 * 1859. 백만 장자 프로젝트
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	vector<int> arr;

	for (int _case = 1; _case <= testcase; _case++) {
		int N;
		long long gain = 0;
		cin >> N;

		arr = vector<int>(N);

		for (int idx = 0; idx < N; idx++) {
			cin >> arr[idx];
		}

		int maxValue = arr[N-1];

		for (int idx = N-2; idx >= 0; idx--) {
			if (maxValue > arr[idx]) {
				gain += (maxValue - arr[idx]);
			}
			else {
				maxValue = arr[idx];
			}
		}

		cout << '#' << _case << " " << gain << endl;
	}

	return 0;
}