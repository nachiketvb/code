#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

void solve_case(void)
{
	int A, B;
	cin >> A >> B;
	vector<float> p(A);
	vector<float> prod(A);
	for (int i = 0; i < A; i++) {
		cin >> p[i];
		if (i == 0) {
			prod[i] = p[i];
		} else {
			prod[i] = prod[i - 1] * p[i];
		}
	}
	int num_expected = A + 2;
	float min_expected = 3 * B;
	for (int i = 0; i < A; i++) {
		int steps_right = 2 * i + B - A + 1;
		int steps_wrong = 2 * i + 2*B - A + 2;
		float prob_right = prod[A - i - 1];
		float prob_wrong = 1.0 - prob_right;
		float expected_value = steps_right * prob_right + steps_wrong * prob_wrong;
		if (expected_value < min_expected) {
			min_expected = expected_value;
		}
	}
	float expected_value = 2 + B;
	if (expected_value < min_expected) {
		min_expected = expected_value;
	}
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(6);
	cout << min_expected;
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
