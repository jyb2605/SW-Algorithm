/*
 * D2
 * 1984. 중간 평균값 구하기
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		vector<int> arr(10);
		double sum = 0;

		for (int i = 0; i < 10; i++) {
			cin >> arr[i];
			sum += arr[i];
		}

		sort(arr.begin(), arr.end());

		sum -= arr[0];
		sum -= arr[9];

		sum /= 8;

		cout << '#' << _case << ' ' << round(sum) << endl;
	}

	return 0;
}