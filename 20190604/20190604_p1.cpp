/*
 * D2
 * 1208. Flatten
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	
	int testcase;
	testcase = 10;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, num;
		cin >> N;

		vector<int> flat;

		for (int i = 0; i < 100; i++) {
			cin >> num;
			flat.push_back(num);
		}

		sort(flat.begin(), flat.end(), cmp);

		cout << "#" << _case << ' ';

		while (N--) {
			flat[0]--;
			flat[99]++;

			if(flat[0] < flat[1]){
				int idx = 1;
				while (flat[0] < flat[idx])
					idx++;
				int tmp = flat[0];
				flat[0] = flat[idx - 1];
				flat[idx - 1] = tmp;
			}

			if (flat[99] > flat[98]) {
				int idx = 98;
				while (flat[99] > flat[idx])
					idx--;
				int tmp = flat[99];
				flat[99] = flat[idx + 1];
				flat[idx + 1] = tmp;
			}
		}

		cout << flat[0] - flat[99] << endl;
	}

	return 0;
}