/*
 * D2
 * 1966. 숫자를 정렬하자
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int first, int second) {
	return (first < second);
}

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, number;
		vector<int> v;
		cin >> N;

		for (int idx = 0; idx < N; idx++) {
			cin >> number;
			v.push_back(number);
		}

		sort(v.begin(), v.end(), cmp);

		cout << '#' << _case << ' ';
		for (int idx = 0; idx < N; idx++) {
			cout << v[idx] << ' ';
		}
		cout << '\n';
	}

	return 0;
}