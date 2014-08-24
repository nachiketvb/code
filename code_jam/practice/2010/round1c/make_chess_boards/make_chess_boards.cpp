#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

void solve_case()
{
	int M, N;
	string line;
	getline(cin, line);
	stringstream sin(line);
	sin >> M >> N;
	vector< vector<int> > bark(M, N);
	map<int, int> boards;
	for (int i = 0; i < M; i++) {
		string line;
		getline(cin, line);
		stringstream sin(line);
		int num_chars = N / 4;
		int square_num = 0;
		for (int j = 0; j < num_chars; j++) {
			char hex_char;
			int hex_digit;
			sin >> hex_char;
			if (hex_char >= '0' && hex_char <= '9') {
				hex_digit = hex_char - '0';
			} else {
				hex_digit = hex_char - 'A' + 10;
			}
			bark[i][square_num++] = ((hex_digit & 8) == 0) ? 0 : 1;
			bark[i][square_num++] = ((hex_digit & 4) == 0) ? 0 : 1;
			bark[i][square_num++] = ((hex_digit & 2) == 0) ? 0 : 1;
			bark[i][square_num++] = hex_digit & 1;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (bark[i][j] == -1)
				continue;
			int length = 1;
			int color = bark[i][j];
			int k = j + 1;
			while (k < N) {
				if (color == bark[i][k])
					break;
				color = bark[i][k];
				k++;
				length++;
			}
			k = j;
			int minimum = length;
			while (k < (j + length)) {
				color = bark[i][k];
				int vert_length = 1;
				for (int l = i + 1; l < M; l++) {
					if (color == bark[l][k])
						break;
					color = bark[l][k];
					vert_length++;
				}
				minimum = (minimum > vert_length) ? vert_length : minimum;
				k++;
			}
			boards[minimum]++;
			for (int l = i; l < (i + minimum); l++) {
				for (int m = j; m < (j + minimum); m++) {
					bark[l][m] = -1;
				}
			}
		}
	}
	cout << boards.size() << endl;
	for (map<int, int>::reverse_iterator itr = boards.rbegin(); itr != boards.rend(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
}

int main()
{
	int T;
	string strbuff;
	getline(cin, strbuff);
	stringstream sin(strbuff);
	sin >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
	}
}
