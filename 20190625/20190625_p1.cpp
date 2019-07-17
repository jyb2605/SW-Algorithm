/*
 * D2
 * 2001. 파리 퇴치
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;

int main() {

	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, M;
		cin >> N >> M;

		map = vector<vector<int>>(N, vector<int>(N));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}

		int maxValue = 0;

		for (int i = 0; i < N - M + 1; i++) {
			for (int j = 0; j < N - M + 1; j++) {
				int sum = 0;
				for (int row = i; row < i + M; row++) {
					for (int col = j; col < j + M; col++) {
						sum += map[row][col];
					}
				}
				maxValue = max(maxValue, sum);
			}
		}

		cout <<'#'<<_case<<' '<< maxValue << endl;
	}

	return 0;
}