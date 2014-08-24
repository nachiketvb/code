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
	vector<string> board(4);
	char outcome = 'D';
	bool winner_found;
	char first_char;
	cin >> board[0];
	cin >> board[1];
	cin >> board[2];
	cin >> board[3];
	for (int i = 0; i < 4; i++) {
		first_char = (board[i][0] == 'T') ? board[i][1] : board[i][0];
		if (first_char == '.') {
			outcome = 'I';
			continue;
		}
		winner_found = true;
		for (int j = 1; j < 4; j++) {
			if ((board[i][j] != 'T') && (board[i][j] != first_char)) {
				winner_found = false;
				break;
			}
		}
		if (winner_found) {
			outcome = first_char;
			goto result;
		}
	}

	for (int i = 0; i < 4; i++) {
		first_char = (board[0][i] == 'T') ? board[1][i] : board[0][i];
		if (first_char == '.') {
			outcome = 'I';
			continue;
		}
		winner_found = true;
		for (int j = 1; j < 4; j++) {
			if ((board[j][i] != 'T') && (board[j][i] != first_char)) {
				winner_found = false;
				break;
			}
		}
		if (winner_found) {
			outcome = first_char;
			goto result;
		}
	}

	
	first_char = (board[0][0] == 'T') ? board[1][1] : board[0][0];
	if (first_char == '.') {
		outcome = 'I';
		goto second_diagonal;
	}
	winner_found = true;
	for (int j = 1; j < 4; j++) {
		if ((board[j][j] != 'T') && (board[j][j] != first_char)) {
			winner_found = false;
			break;
		}
	}
	if (winner_found) {
		outcome = first_char;
		goto result;
	}

second_diagonal:
	
	first_char = (board[0][3] == 'T') ? board[1][2] : board[0][3];
	if (first_char == '.') {
		outcome = 'I';
		goto result;
	}
	winner_found = true;
	for (int j = 1; j < 4; j++) {
		if ((board[j][(3 - j)] != 'T') && (board[j][(3 - j)] != first_char)) {
			winner_found = false;
			break;
		}
	}
	if (winner_found) {
		outcome = first_char;
		goto result;
	}
result:
	bool dot_found = false;
	switch (outcome) {
		case 'O':
			cout << "O won";
			break;
		case 'X':
			cout << "X won";
			break;
		case 'D':
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (board[i][j] == '.') {
						dot_found = true;
					}
				}
			}
			if (dot_found) {
				cout << "Game has not completed";
			} else {
				cout << "Draw";
			}
			break;
		case 'I':
			cout << "Game has not completed";
			break;
		default:
			cout << "Invalid input!";
			break;
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
