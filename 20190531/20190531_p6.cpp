/*
 * D2
 * 1974. 스도쿠 검증
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int testcase;
	cin >> testcase;

	

	for (int _case = 1; _case <= testcase; _case++) {
		bool isValid = true;
		vector<vector<vector<bool>>> box(3, vector<vector<bool>>(3, vector<bool>(9, false)));
		vector<vector<bool>> row(9, vector<bool>(9, false));
		vector<vector<bool>> col(9, vector<bool>(9, false));

		vector<vector<int>> map(9, vector<int>(9));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];

				if (!row[i][map[i][j] - 1]) {
					row[i][map[i][j] - 1] = true;
				}
				else {
					isValid = false;
				}
				if (!col[map[i][j] - 1][j]) {
					col[map[i][j] - 1][j] = true;
				}
				else {
					isValid = false;
				}

				if (!box[i / 3][j / 3][map[i][j] - 1]) {
					box[i / 3][j / 3][map[i][j] - 1] = true;
				}
				else {
					isValid = false;
				}
			}
		}

		cout << "#" << _case << ' ' << (isValid ? 1 : 0) << endl;
	}

	return 0;
}