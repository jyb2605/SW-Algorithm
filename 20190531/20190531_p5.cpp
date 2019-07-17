/*
 * D2
 * 1961. 숫자 배열 회전
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

		vector<vector<int>> matrix(N, vector<int>(N));
		vector<vector<vector<int>>> sub(3, vector<vector<int>>(N, vector<int>(N)));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> matrix[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sub[0][i][j] = matrix[N - j - 1][i];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sub[1][i][j] = sub[0][N - j - 1][i];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				sub[2][i][j] = sub[1][N - j - 1][i];
			}
		}

		cout << "#" << _case << "\n";

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << sub[0][i][j];
			}
			cout << ' ';
			for (int j = 0; j < N; j++) {
				cout << sub[1][i][j];
			}
			cout << ' ';
			for (int j = 0; j < N; j++) {
				cout << sub[2][i][j];
			}
			cout << '\n';

		}
		
	}

	return 0;
}