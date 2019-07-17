/*
 * D3
 * 1240. 단순 2진 암호코드
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {

	int testcase;
	cin >> testcase;

	int decoded[10][4] = {
		{3,2,1,1},
		{2,2,2,1},
		{2,1,2,2},
		{1,4,1,1},
		{1,1,3,2},
		{1,2,3,1},
		{1,1,1,4},
		{1,3,1,2},
		{1,2,1,3},
		{3,1,1,2}
	};

	for (int _case = 1; _case <= testcase; _case++) {

		int height, width;
		int result;
		cin >> height >> width;

		vector<vector<char>> map(height, vector<char>(width));
		vector<vector<int>> heightMatrix(height, vector<int>(width, 0));

		getchar();
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				map[i][j] = getchar();
			}
			getchar();
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0) {
					heightMatrix[i][j] = 1;
					continue;
				}

				if (map[i][j] == map[i - 1][j]) {
					heightMatrix[i][j] = heightMatrix[i - 1][j] + 1;
				}
				else {
					heightMatrix[i][j] = 1;
				}
			}
		}

		for (int i = 4; i < height; i++) {
			for (int j = 0; j < width; j++) {
				int ptr = map[i][j];
				int dup = 1;
				bool isSuccess = true;


				for (int k = j + 1; k < j + 56 && k < width; k++) {
					if (heightMatrix[i][k] < 5) {
						isSuccess = false;
						break;
					}
					
					if (map[i][k] == ptr)
						dup++;
					else {
						ptr = map[i][k];
						dup = 1;
					}

					if (dup > 4) {
						isSuccess = false;
						break;
					}
				}


				if (isSuccess) {
					vector<int> proportion;
					ptr = map[i][j];
					dup = 1;

					for (int k = j + 1; k < j + 56 && k < width; k++) {
						if (map[i][k] == ptr)
							dup++;
						else {
							proportion.push_back(dup);
							dup = 1;
							ptr = map[i][k];
						}
							
					}
					proportion.push_back(dup);

					if (proportion.size() == 32) {
						vector<int> encrypted;

						int idx = 0;

						while (idx < 32) {
							for (int num = 0; num < 10; num++) {
								if (decoded[num][0] == proportion[idx] && decoded[num][1] == proportion[idx + 1]
									&& decoded[num][2] == proportion[idx + 2] && decoded[num][3] == proportion[idx + 3]) {
									encrypted.push_back(num);
									break;
								}
							}

							idx += 4;
						}

						if (encrypted.size() == 8) {
							int sum = 0;

							for (int i = 0; i < 7; i++) {
								if (i % 2 == 0) {
									sum += encrypted[i] * 3;
								}
								else {
									sum += encrypted[i];
								}
							}

							sum += encrypted[7];
							if (sum % 10 == 0) {
								sum = 0;
								for (int i = 0; i < 8; i++) {
									sum += encrypted[i];
								}
								result = sum;
							}
							else {
								result = 0;
							}
						}
					}

				}
			}
		}


		cout << '#' << _case << ' ' << result << endl;
	}


	return 0;
}