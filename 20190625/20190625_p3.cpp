/*
 * D4
 * 1222. 계산기1
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
				if (postorder.size() == length - 1) {
					postorder.push(s.top());
				}
			}
			else {
				//operator
				if (s.empty()) {
					s.push(input);
				}
				else {
					if (input == '+' || input == '-') {
						while (s.top() == '+' || s.top() == '-') {
							postorder.push(s.top());
							s.pop();
							if (s.empty())
								break;
						}
						s.push(input);
					}
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
				int res = value1 + value2;
				result.push(res);
			}
		}

		cout << "#" << _case << ' ' << result.top() << endl;
	}
	
	return 0;
}