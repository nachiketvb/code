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
	int N, K;
	string line;
	getline(cin, line);
	stringstream ss(line);
	ss >> N >> K;
	vector<string> board(N);
	for (int i = 0; i < N; i++) {
		getline(cin, board[i]);
	}
	vector<string> rotated_board(N, string(N,'.'));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			rotated_board[i][j] = board[N - 1 - j][i];
		}
	}
	vector<int> bottom(N, N - 1);
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < N; j++) {
			if (rotated_board[i][j] != '.') {
				char temp = rotated_board[i][j];
				rotated_board[i][j] = rotated_board[bottom[j]][j];
				rotated_board[bottom[j]][j] = temp;
				bottom[j]--;
			}
		}
	}
	bool red = false, blue = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (rotated_board[i][j] == '.') {
			       continue;
			}
			char first = rotated_board[i][j];
			int k;
			if ((j + K - 1) < N) {
				for (k = 0; k < K; k++) {
					if (rotated_board[i][j + k] != first) {
						break;
					}
				}
				if (k == K) {
					if (first == 'R') {
						red = true;
					} else if (first == 'B') {
						blue = true;
					}
				}
			}
			if ((i + K - 1) < N) {
				for (k = 0; k < K; k++) {
					if (rotated_board[i + k][j] != first) {
						break;
					}
				}
				if (k == K) {
					if (first == 'R') {
						red = true;
					} else if (first == 'B') {
						blue = true;
					}
				}
			}
			if (((i + K - 1) < N) && ((j + K - 1) < N)) { 
				for (k = 0; k < K; k++) {
					if (rotated_board[i + k][j + k] != first) {
						break;
					}
				}
				if (k == K) {
					if (first == 'R') {
						red = true;
					} else if (first == 'B') {
						blue = true;
					}
				}
			}
			if (((i - K + 1) >= 0) && ((j + K) < N)) { 
				for (k = 0; k < K; k++) {
					if (rotated_board[i - k][j + k] != first) {
						break;
					}
				}
				if (k == K) {
					if (first == 'R') {
						red = true;
					} else if (first == 'B') {
						blue = true;
					}
				}
			}
		}
	}
	if ((red == true) && (blue == true)) {
		cout << "Both";
	} else if (red == true) {
		cout << "Red";
	} else if (blue == true) {
		cout << "Blue";
	} else {
		cout << "Neither";
	}
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
