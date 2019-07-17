/*
 * D2
 * 1284. 수도 요금 경쟁
 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		int P, Q, R, S, W;
		cin >> P >> Q >> R >> S >> W;

		int pVal = P * W, qVal = Q;

		if (W > R) {
			qVal += (W - R) * S;
		}
		
		cout << "#" << _case << ' ' << ((pVal > qVal) ? qVal : pVal) << endl;
	}

	return 0;
}