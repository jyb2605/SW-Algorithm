/*
 * D2
 * 2007. 패턴 마디의 길이
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		string input;
		cin >> input;
		vector<char> repeat;

		repeat.push_back(input[0]);

		for (int idx = 1; idx < input.length(); idx++) {
			if (repeat[0] == input[idx]) {
				bool isSame = true;

				for (int sub = idx; sub < repeat.size() + idx; sub++) {
					if (input[sub] != repeat[sub - idx]) {
						isSame = false;
						break;
					}
				}
				if (isSame) {
					cout << "#" << _case << " " << repeat.size() << endl;
					break;
				}
				else {
					repeat.push_back(input[idx]);
				}
			}
			else {
				repeat.push_back(input[idx]);
			}
		}

	}
	return 0;
}