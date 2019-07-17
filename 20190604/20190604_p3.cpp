/*
 * D3
 * 2817. 부분 수열의 합
 */
#include <iostream>
#include <vector>
using namespace std;

int N, target;
int result;
vector<int> arr;

void func(int sum, int idx) {
	
	for (int i = idx; i < N; i++) {
		sum += arr[i];

		if (sum == target) {
			result++;
			sum -= arr[i];
			continue;
		}

		if (sum < target) {
			func(sum, i + 1);
		}

		sum -= arr[i];
	}
	
}

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		result = 0;
		cin >> N >> target;

		arr = vector<int>(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		func(0, 0);

		cout << "#" << _case << ' ' << result << endl;

	}

	return 0;
}