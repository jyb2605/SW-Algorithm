/*
 * D2
 * 2005. 파스칼의 삼각형
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N;
		cin >> N;

		vector<int> cur = {1};
		vector<int> next;

		cout << '#' << _case << endl;

		for (int row = 0; row < N; row++) {
			for (int idx = 0; idx < cur.size(); idx++) {
				cout << cur[idx] << ' ';
			}
			cout << endl;
			next.push_back(1);
			
			for (int idx = 1; idx < row + 1; idx++) {
				next.push_back(cur[idx - 1] + cur[idx]);
			}
			next.push_back(1);
			cur = next;
			next.clear();
		}
	
	}

	return 0;
}