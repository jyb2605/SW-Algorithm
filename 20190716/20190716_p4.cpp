/*
 * D2
 * 1979. 어디에 단어가 들어갈 수 있을까
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int N, M, count = 0;
		cin >> N >> M;
		vector<vector<int>> map(N, vector<int>(N));

		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				cin >> map[row][col];
			}
		}

		for (int idx = 0; idx < N; idx++) {
			for (int idx2 = 0; idx2 < N; idx2++) {
				if (map[idx][idx2] == 0) {
					continue;
				}
				else {
					int tmp = 0;
					while (map[idx][idx2] == 1) {
						tmp++;
						idx2++;
						if (idx2 >= N)
							break;
					}
					if (tmp == M)
						count++;
				}
			}
		}

		for (int idx = 0; idx < N; idx++) {
			for (int idx2 = 0; idx2 < N; idx2++) {
				if (map[idx2][idx] == 0) {
					continue;
				}
				else {
					int tmp = 0;
					while (map[idx2][idx] == 1) {
						tmp++;
						idx2++;
						if (idx2 >= N)
							break;
					}
					if (tmp == M)
						count++;
				}
			}
		}


		cout << '#' << _case << ' '<< count << '\n';
	}

	return 0;
}