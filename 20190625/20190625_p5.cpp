/*
 * D4
 * 1224. 계산기3
 */
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int main() {

	for (int _case = 1; _case <= 10; _case++) {
		int length;
		stack<char> s;
		queue<char> postorder;

		cin >> length;

		char input;
		getchar();

		// input & inorder to postorder
		for (int i = 0; i < length; i++) {
			input = getchar();

			if (input > 48 && input < 58) {
				//operand
				postorder.push(input);
				if (i == length - 1) {
					while (!s.empty()) {
						postorder.push(s.top());
						s.pop();
					}
				}
			}
			else {
				//operator
				if (input == '+' || input == '-') {
					if (s.empty()) {
						s.push(input);
						continue;
					}

					while (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/') {
						postorder.push(s.top());
						s.pop();
						if (s.empty())
							break;
					}
					s.push(input);
				}
				else if (input == '*' || input == '/') {
					if (s.empty()) {
						s.push(input);
						continue;
					}

					while (s.top() == '*' || s.top() == '/') {
						postorder.push(s.top());
						s.pop();
						if (s.empty())
							break;
					}
					s.push(input);
				}
				else if (input == '(') {
					s.push(input);
				}
				else if (input == ')') {
					while (s.top() != '(') {
						postorder.push(s.top());
						s.pop();
					}
					s.pop();
				}
			}
		}

		stack<int> result;

		// calculate postorder
		while (!postorder.empty()) {
			char value = postorder.front();
			postorder.pop();

			if (value > 48 && value < 58) {
				result.push(value - 48);
			}
			else {
				int value1 = result.top();
				result.pop();
				int value2 = result.top();
				result.pop();

				// identify operator
				int res;
				switch (value) {
				case '+':
					res = value1 + value2;
					break;

				case '*':
					res = value1 * value2;
					break;
				}

				result.push(res);
			}
		}

		cout << "#" << _case << ' ' << result.top() << endl;
	}

	return 0;
}