/*
 * D2
 * 1928. Base64 Decoder
 */
#include <iostream>
#include <string>
using namespace std;

int main() {

	int testcase, cnt;
	char * MSB = new char[3];
	uint32_t msb;
	string input;

	cin >> testcase;

	for (int time = 1; time < testcase + 1; time++) {
		cin >> input;
		cnt = 4;
		msb = 0;
		cout << "#" << time << ' ';

		for (int idx = 0; idx < input.length(); idx++) {
			if (input[idx] >= 48 && input[idx] <= 57) {
				msb += (input[idx] + 4);
			}
			else if (input[idx] >= 65 && input[idx] <= 90) {
				msb += (input[idx] - 65);
			}
			else if (input[idx] >= 97 && input[idx] <= 122) {
				msb += (input[idx] - 71);
			}
			else if (input[idx] == '+') {
				msb += 62;
			}
			else if (input[idx] == '/') {
				msb += 63;
			}

			cnt--;
			if (cnt == 0) {
				cnt = 4;
				msb *= 256;
				char asd[4];
				memcpy(asd, &msb, 4);
				msb = 0;
				printf("%c", asd[3]);
				printf("%c", asd[2]);
				printf("%c", asd[1]);
			}
			else {
				msb *= 64;
			}
		}
		cout << endl;
	}

	return 0;
}