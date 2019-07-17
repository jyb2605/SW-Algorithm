/*
 * D2
 * 1983. 조교의 성적 매기기
 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool desc(double a, double b) {
	return a > b;
}

int main() {

	int testcase;
	cin >> testcase;

	for (int _case = 1; _case <= testcase; _case++) {
		cout << "#" << _case << ' ';

		int student, target;
		cin >> student >> target;

		int mid, fin, assign;
		vector<double> res;
		double targetValue;

		for (int idx = 0; idx < student; idx++) {
			cin >> mid >> fin >> assign;
			double tmp = (double)mid * 0.35 + (double)fin * 0.45 + (double)assign * 0.2;
			res.push_back(tmp);

			if (idx + 1 == target) {
				targetValue = tmp;
			}
		}

		sort(res.begin(), res.end(), desc);

		int idx = 0;
		while (res[idx] != targetValue) 
			idx++;

		int tmp = student / 10;

		if (idx < tmp) {
			cout << "A+" << endl;
		}
		else if (idx < tmp * 2) {
			cout << "A0" << endl;
		}
		else if (idx < tmp * 3) {
			cout << "A-" << endl;
		}
		else if (idx < tmp * 4) {
			cout << "B+" << endl;
		}
		else if (idx < tmp * 5) {
			cout << "B0" << endl;
		}
		else if (idx < tmp * 6) {
			cout << "B-" << endl;
		}
		else if (idx < tmp * 7) {
			cout << "C+" << endl;
		}
		else if (idx < tmp * 8) {
			cout << "C0" << endl;
		}
		else if (idx < tmp * 9) {
			cout << "C-" << endl;
		}
		else {
			cout << "D0" << endl;
		}
	}

	return 0;
}