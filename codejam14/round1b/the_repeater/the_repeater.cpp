#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void solve(void)
{
	char strings[100][101];
	int N;
	int histo[100][101];
	int ndistinct = 0;
	int index[100];
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> strings[i];
		index[i] = 0;
		for (int j = 0; j < 101; ++j) {
			histo[i][j] = 0;
		}
	}
	while (1) {
		char c;
		c = strings[0][index[0]];
		if (c == '\0') {
			for (int i = 1; i < N; ++i) {
				if (strings[i][index[i]] != '\0') {
					cout << "Fegla Won" << endl;
					return;
				}
			}
			break;
		}
		while (strings[0][index[0]] == c) {
			++index[0];
			++histo[0][ndistinct];
		}
		for (int i = 1; i < N; ++i) {
			if (strings[i][index[i]] != c) {
				cout << "Fegla Won" << endl;
				return;
			}
			while (strings[i][index[i]] == c) {
				++index[i];
				++histo[i][ndistinct];
			}
		}
		++ndistinct;
	}
	int moves = 0;
	for (int i = 0; i < ndistinct; ++i) {
		int sum = 0;
		for (int j = 0; j < N; ++j) {
			sum += histo[j][i];
		}
		int average = ((double)sum + 0.5) / N;
		for (int j = 0; j < N; ++j) {
			moves += abs(average - histo[j][i]);
		}
	}
	cout << moves << endl;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}
