/*
 * D2
 * 1989. 초심자의 회문 검사
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		string input;
		cin >> input;

		int begin = 0, end = input.length() - 1;
		bool isPalindrome = true;

		while (begin < end) {
			if (input[begin] != input[end]) {
				isPalindrome = false;
				break;
			}
			begin++;
			end--;
		}

		cout << "#" << _case << ' ' << (isPalindrome ? 1 : 0) << endl;
	}

	return 0;
}