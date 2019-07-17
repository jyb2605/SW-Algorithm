/*
 * D3
 * 2806. N-Queen
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, result;

void func(vector<vector<bool>> map, int n) {
	if (n == N) {
		result++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!map[n][i]) {
			vector<vector<bool>> tmp = map;
			//����
			tmp[n] = vector<bool>(N, true);

			//����
			for (int j = 0; j < N; j++) {
				tmp[j][i] = true;
			}

			//�밢��
			int val = min(n, i);
			int xPos = n - val, yPos = i - val;
			while (xPos != N && yPos != N) {
				tmp[xPos][yPos] = true;
				xPos++;
				yPos++;
			}

			val = min(N - n - 1, i);
			xPos = n + val, yPos = i - val;
			while (xPos != 0 && yPos != N) {
				tmp[xPos][yPos] = true;
				xPos--;
				yPos++;
			}

			func(tmp, n + 1);
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		cin >> N;
		result = 0;
		vector<vector<bool>> map(N, vector<bool>(N, false));

		func(map, 0);

		cout << "#" << _case << ' ' << result << endl;
	}

	return 0;
}
